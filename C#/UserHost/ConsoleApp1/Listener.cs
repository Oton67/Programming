using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.Security.Cryptography;
using System.Text;

namespace Listener {

    class Listener {
        

        static void HttpTest() {
           
            while (true) {
                HttpListener listener = new HttpListener();
                listener.Prefixes.Add("http://localhost:51111/test/");

               //TripleDES tdes = new TripleDESCryptoServiceProvider();//gr

                listener.Start();
                Console.WriteLine("Listening...");
                HttpListenerContext context = listener.GetContext();
                HttpListenerRequest request = context.Request;
                Console.WriteLine(request.RawUrl);
                string ime = request.QueryString["ime"];
                string prezime = request.QueryString["prezime"];

                HttpListenerResponse response = context.Response;
                string responseString = "<HTML><BODY>Pozdrav, " + ime + " " + prezime + "!</BODY></HTML>";
                byte[] buffer = Encoding.UTF8.GetBytes(responseString);
                response.ContentLength64 = buffer.Length;
                Stream output = response.OutputStream;
                output.Write(buffer, 0, buffer.Length);
                output.Close();

                listener.Stop();
            }
        }

        //=====================================================================

        static void TCPServerTest(TripleDES tdes) {
            
            TcpListener server = new TcpListener(IPAddress.Any, 54321);
            server.Start();
            while (true) {
                Console.WriteLine("server> server ceka ...");
                TcpClient klijent = server.AcceptTcpClient();               // klijent objekt je potreban da mu server moze slati poruke
                Console.WriteLine("server> klijent spojen ...");
                NetworkStream nwstream = klijent.GetStream();               // veza servera s klijentom
                Console.WriteLine("server> cekaj na poruku ...");
                string poruka = new BinaryReader(nwstream).ReadString();    // cekaj na poruku
                Console.WriteLine("server> stigla poruka ...");
                if (poruka == ".") {
                    klijent.Close();
                    nwstream.Close();
                    break;
                }
                else {
                    BinaryWriter w = new BinaryWriter(nwstream);
                    w.Write("server primio poruku: " + desifriranje(poruka,tdes));
                    w.Flush();
                }
            }

            server.Stop();
        }

        static void TCPKlijentTest(TripleDES tdes) {
            while (true) {
                
                TcpClient klijent = new TcpClient("localhost", 54321);      // spajanje na server
                //Console.WriteLine("klijent> klijent spojen ...");
                //Thread.Sleep(2000);
                NetworkStream nwstream = klijent.GetStream();               // veza klijenta sa serverom
                BinaryWriter writer = new BinaryWriter(nwstream);
               // Console.Write("poruka? ");
                string poruka = Console.ReadLine();
                writer.Write(sifriranje(poruka, tdes));                                       // slanje poruke
                writer.Flush();
                if (poruka == ".") {
                    klijent.Close();
                    nwstream.Close();
                    break;
                }
                else {
                    string odgovor = new BinaryReader(nwstream).ReadString();   // citamo odgovor servera
                    Console.WriteLine(odgovor);
                }
            }
        }

        // ====================================================================

        static byte[] Kriptirano(string plainText, byte[] Key, byte[] IV) {
            if (plainText == null || plainText.Length <= 0)
                throw new ArgumentNullException("plainText");
            if (Key == null || Key.Length <= 0)
                throw new ArgumentNullException("Key");
            if (IV == null || IV.Length <= 0)
                throw new ArgumentNullException("IV");
            byte[] encrypted;

            using (Aes aes = Aes.Create()) {
                aes.Key = Key;
                aes.IV = IV;

                ICryptoTransform encryptor = aes.CreateEncryptor(aes.Key, aes.IV);
                using (MemoryStream msEncrypt = new MemoryStream()) {
                    using (CryptoStream csEncrypt = new CryptoStream(msEncrypt, encryptor, CryptoStreamMode.Write)) {
                        using (StreamWriter swEncrypt = new StreamWriter(csEncrypt)) {
                            swEncrypt.Write(plainText);
                        }
                        encrypted = msEncrypt.ToArray();
                    }

                }
            }

            return encrypted;
        }

        static string Dekriptirano(byte[] cipherText, byte[] Key, byte[] IV) {
            if (cipherText == null || cipherText.Length <= 0)
                throw new ArgumentNullException("cipherText");
            if (Key == null || Key.Length <= 0)
                throw new ArgumentNullException("Key");
            if (IV == null || IV.Length <= 0)
                throw new ArgumentNullException("IV");

            string plaintext = null;
            using (Aes aes = Aes.Create()) {
                aes.Key = Key;
                aes.IV = IV;

                ICryptoTransform decryptor = aes.CreateDecryptor(aes.Key, aes.IV);
                using (MemoryStream msDecrypt = new MemoryStream(cipherText)) {
                    using (CryptoStream csDecrypt = new CryptoStream(msDecrypt, decryptor, CryptoStreamMode.Read)) {
                        using (StreamReader srDecrypt = new StreamReader(csDecrypt)) {
                            plaintext = srDecrypt.ReadToEnd();
                        }
                    }
                }
            }

            return plaintext;
        }

        static string sifriranje(string Sporuka, TripleDES tdes)
        {
            // *** SIFRIRANJE ***
            //Console.WriteLine("Triple DES");

            //byte[] kljuc = Encoding.ASCII.GetBytes("oop2_tvz_7654321");     // duljina u bitovima moze biti 128 ili 192 za Triple DES
            //byte[] initVektor = Encoding.ASCII.GetBytes("initvector111");

            byte[] poruka = Encoding.ASCII.GetBytes(Sporuka);
            MemoryStream ms = new MemoryStream();   // rezerviraj memorijski prostor

            // duljina u bitovima moze biti 128 ili 192 za Triple DES
            
            //Console.WriteLine($"Kljuc: {Convert.ToBase64String(tdes.Key)}, ({tdes.Key.Length * 8} bytes)");

            CryptoStream cs = new CryptoStream(ms, tdes.CreateEncryptor(tdes.Key, tdes.IV), CryptoStreamMode.Write);
            cs.Write(poruka, 0, poruka.Length);
            cs.Close();

            string sifriranaPoruka = Convert.ToBase64String(ms.ToArray());
            Console.WriteLine($"sifrirano: {sifriranaPoruka}");

            return sifriranaPoruka;
        }

        static string desifriranje(string sifriranaPoruka, TripleDES tdes)
        {
           
            byte[] sifra = Convert.FromBase64String(sifriranaPoruka);
            MemoryStream ms = new MemoryStream(sifra);

            ICryptoTransform desifrator = tdes.CreateDecryptor(tdes.Key, tdes.IV);
            CryptoStream cs = new CryptoStream(ms, desifrator, CryptoStreamMode.Read);

            StreamReader citac = new StreamReader(cs);
            string desifriranaPoruka = citac.ReadToEnd();
            Console.WriteLine($"desifrirano: {desifriranaPoruka}");

            return desifriranaPoruka;
        }

            static void Main(string[] args) {

            TripleDES tdes = new TripleDESCryptoServiceProvider();
            // *** KOMUNIKACIJE ***
            new Thread(() => { TCPServerTest(tdes); }).Start();
            TCPKlijentTest(tdes);

            //-----------------------------------------------------------------
/*
            // *** SIFRIRANJE ***
            Console.WriteLine("Triple DES");

            //byte[] kljuc = Encoding.ASCII.GetBytes("oop2_tvz_7654321");     // duljina u bitovima moze biti 128 ili 192 za Triple DES
            //byte[] initVektor = Encoding.ASCII.GetBytes("initvector111");

            byte[] poruka = Encoding.ASCII.GetBytes("tajna poruka");
            MemoryStream ms = new MemoryStream();   // rezerviraj memorijski prostor

            // duljina u bitovima moze biti 128 ili 192 za Triple DES
            //TripleDES tdes = new TripleDESCryptoServiceProvider();
            Console.WriteLine($"Kljuc: {Convert.ToBase64String(tdes.Key)}, ({tdes.Key.Length * 8} bytes)");

            CryptoStream cs = new CryptoStream(ms, tdes.CreateEncryptor(tdes.Key, tdes.IV), CryptoStreamMode.Write);
            cs.Write(poruka, 0, poruka.Length);
            cs.Close();

            string sifriranaPoruka = Convert.ToBase64String(ms.ToArray());
            Console.WriteLine($"sifrirano: {sifriranaPoruka}");

            // *** DESIFRIRANJE ***

            byte[] sifra = Convert.FromBase64String(sifriranaPoruka);
            ms = new MemoryStream(sifra);

            ICryptoTransform desifrator = tdes.CreateDecryptor(tdes.Key, tdes.IV);
            cs = new CryptoStream(ms, desifrator, CryptoStreamMode.Read);

            StreamReader citac = new StreamReader(cs);
            string desifriranaPoruka = citac.ReadToEnd();
            Console.WriteLine($"desifrirano: {desifriranaPoruka}");

            //-----------------------------------------------------------------

            Console.WriteLine("\nAES");
            try {
                string original = "Neka poruka za AES demo ...";

                using (Aes aes = Aes.Create()) {
                    Console.WriteLine($"Kljuc: {Convert.ToBase64String(aes.Key)}, ({aes.Key.Length * 8} bytes)");
                    byte[] kriptiran_sadrzaj = Kriptirano(original, aes.Key, aes.IV);
                    string dekriptiran_sadrzaj = Dekriptirano(kriptiran_sadrzaj, aes.Key, aes.IV);
                    Console.WriteLine("Original:   {0}", original);
                    Console.WriteLine("Dekriptirano: {0}", dekriptiran_sadrzaj);
                }
            }
            catch (Exception e) {
                Console.WriteLine("Error: {0}", e.Message);
            }*/
        }
    }
}
