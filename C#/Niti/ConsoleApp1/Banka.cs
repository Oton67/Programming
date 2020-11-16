using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Niti
{
    class Banka
    {
        public static void Pokreni()
        {
            Banka primjer = new Banka();

            Thread p1 = new Thread(primjer.OsobaA);
            Thread p2 = new Thread(primjer.OsobaB);

            p1.Start();
            p2.Start();

            p1.Join();
            p2.Join();

            Console.WriteLine($"stanje u banci: {primjer.banka}kn");
            
        }

        readonly object Slobodno = new object();
        bool flag = false;
        public int banka = 10;
        int iznosA = 10;
        int iznosB = 5;


        public void OsobaA()
        {
            Console.WriteLine($"----- Osoba A zeli podic {iznosA}kn");

            
            if (flag)
            {
                Console.WriteLine("Osoba A mora cekat");
            }

            lock (Slobodno)
            {    
                Console.WriteLine("Osoba A koristi racun");
                flag = true;
                if (banka >= iznosA)
                {
                    Console.WriteLine($"Bankovni racun sadrzi {banka}kn");
                    Thread.Sleep(500);
                    Console.WriteLine($"Osoba A vadi {iznosA}kn");
                    Skladistar(iznosA);

                    Console.WriteLine("----- Osoba A je izvadila novac");
                }
                else
                {
                    Console.WriteLine("U bankovnom racunu nema dovoljno novca");
                }
                flag = false;    
                  
            }
        }

        public void OsobaB()
        {
            Console.WriteLine($"----- Osoba B zeli podic {iznosB}kn");


            if (flag)
            {
                Console.WriteLine("Osoba B mora cekat");
            }

            lock (Slobodno)
            {
                Console.WriteLine("Osoba B koristi racun");
                flag = true;
                if (banka >= iznosB)
                {
                    Console.WriteLine($"Bankovni racun sadrzi {banka}kn");
                    Thread.Sleep(500);
                    Console.WriteLine($"Osoba B vadi {iznosB}kn");
                    Skladistar(iznosB);

                    Console.WriteLine("----- Osoba B je izvadila novac");
                }
                else
                {
                    Console.WriteLine("U bankovnom racunu nema dovoljno novca");
                }
                flag = false;
                
            }
        }

        void Skladistar(int n)
        {
            Console.WriteLine($"iznos bankovnog racuna se smanjuje za {n}kn");
            Thread.Sleep(500);
            banka -= n;
        }
    }

}
