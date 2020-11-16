using System.Drawing;
using System.Windows.Forms;

namespace WindowsFormsApp1 {
    abstract class Grafikon {
        // konstruktor
        // objekti se prenose preko reference (nema * ili &)
        public Grafikon(Form f) {
            Forma = f;
            PostaviDimenzije();
        }

        // *** ovo moze biti 'private'
        public void PostaviDimenzije() {
            LijevaMargina = 10;
            GornjaMargina = 10;
            VisinaOkvira = Forma.Height - 60;

            // groupBox_Kontrole treba postaviti na 'public' u GlavnaForma.Designer.cs
            // Forma mora biti svedena na GlavnaForma koja je podklasa klase Form
            SirinaOkvira = ((GlavnaForma)Forma).groupBox_Kontrole.Location.X - 20;
        }

        public abstract void Prikazi();

        // *** ovo moze biti 'protected' (za sada ne zbog testiranja)
        public virtual void PripremiPrikaz() {
            GrafickiObjekt = Forma.CreateGraphics();
            _NacrtajOkvir();
        }

        public virtual void Obrisi() {
            GrafickiObjekt.Clear(Forma.BackColor);
        }

        public Graphics GrafickiObjekt;
        public Form Forma;
        public int LijevaMargina;
        public int GornjaMargina;
        public int VisinaOkvira;
        public int SirinaOkvira;

        //=====================================================================

        private void _NacrtajOkvir() {
            GrafickiObjekt.DrawRectangle(new Pen(Color.Black, 1),
                                  LijevaMargina,
                                  GornjaMargina,
                                  SirinaOkvira,
                                  VisinaOkvira);

            GrafickiObjekt.FillRectangle(new SolidBrush(Color.Beige),
                                    LijevaMargina + 1,
                                    GornjaMargina + 1,
                                    SirinaOkvira - 1,
                                    VisinaOkvira - 1);
        }
    }
}
