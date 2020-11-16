using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace BazaPodataka {
    class BazaPodataka {
        static void Citanje() {
            /*
            Primjer connection stringa za lab:
            Data Source=ALLLAB-PC-00;Initial Catalog=Vjezbe;User Id=sa;Password=student
            */
            string connectionString = "Data Source=.AUDIT-PC-17\\SQLEXPRESS;Initial Catalog=OOP2;Integrated Security=true";
            string upit = "SELECT * FROM dbo.predmeti";

            using (SqlConnection connection = new SqlConnection(connectionString)) {
                SqlCommand command = new SqlCommand(upit, connection);
                try {
                    connection.Open();
                    SqlDataReader reader = command.ExecuteReader();

                    Console.WriteLine("BR.ST.\tKRATICA\tPREDMET");
                    Console.WriteLine("------\t-------\t-------");
                    int ukupnoStudenata = 0;
                    while (reader.Read()) {
                        Console.WriteLine($"{reader["br_studenata"]}\t{reader["kratica"]}\t{reader["predmet"]}");
                        ukupnoStudenata += (int)reader["br_studenata"];
                    }
                    Console.WriteLine("\n---");
                    Console.WriteLine($"UKUPNO STUDENATA: {ukupnoStudenata}");
                    reader.Close();
                } catch (Exception ex) {
                    Console.WriteLine(ex.Message);
                }
            }
        }

        static void Pisanje() {
            string connectionString = "Data Source=.AUDIT-PC-17\\SQLEXPRESS;Initial Catalog=OOP2;Integrated Security=true";
            string sql = "INSERT INTO dbo.predmeti VALUES(44, 'UUI', 'uvod u umjetnu inteligenciju')";

            using (SqlConnection connection = new SqlConnection(connectionString)) {
                SqlCommand cmd = new SqlCommand(sql, connection);
                connection.Open();
                cmd.ExecuteNonQuery();
                connection.Close();
            }
        }

        static void Main(string[] args) {
            Citanje();
            Pisanje();

            byte[] poruka = Encoding.ASCII.GetBytes("lozinka123");
            SHA1 sha = new SHA1CryptoServiceProvider();
            byte[] rezultat = sha.ComputeHash(poruka);
            Console.WriteLine($"hash: {Convert.ToBase64String(rezultat)}");
        }
    }
}
