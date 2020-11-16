using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;

namespace WindowsFormsApp1 {
    abstract class KoordinatniGrafikon : Grafikon {
        public KoordinatniGrafikon(Form f, List<Tuple<float, string>> vrijednosti) : base(f) {
            Vrijednosti = vrijednosti;
        }

        public override void PripremiPrikaz() {
            base.PripremiPrikaz();
            _NacrtajKoordinate();
        }

        //=====================================================================

        /*
         * Baza je crta x-koordinate.
         */
        private void _IzracunajBazu() {
            AbsMax = Vrijednosti.Max(v => Math.Abs(v.Item1));     // treba za skalu da bi znali koja je vrijednost najveca
            Min = Vrijednosti.Min(v => v.Item1);
            if (Min < 0) {
                Baza = VisinaOkvira / 2;    // x-koordinata je na sredini
            } else {
                Baza = VisinaOkvira - 20;   // x-koordinata je blizu donje margine
            }

            MinY = GornjaMargina + 20;
        }

        private void _NacrtajKoordinate() {
            _IzracunajBazu();

            // za isprekidanu crtu
            Pen pen = new Pen(Color.Red, 1);
            float[] tekstura = { 2, 4 };    // 2 tocke, 4 prazno, 2 tocke, 4 prazno, ...
            pen.DashPattern = tekstura;

            // x-koordinata
            GrafickiObjekt.DrawLine(new Pen(Color.Black, 2),
                                    LijevaMargina + MARGINA_KOORDINATA,
                                    Baza,
                                    SirinaOkvira,   // ovo je x2, ne duljina crte (kao kod sirine pravokutnika)
                                    Baza);

            // y-koordinata
            GrafickiObjekt.DrawLine(new Pen(Color.Black, 2),
                                    LijevaMargina + MARGINA_KOORDINATA,
                                    MinY,
                                    LijevaMargina + MARGINA_KOORDINATA,
                                    Baza);

            float korak = (Baza - MinY) / 10;   // podijeli y-koordinatu na 10 dijelova
            float vrijednostSkale = 0;
            float korakSkale = AbsMax / 10;     // najveca apsolutna vrijednost / 10
            float y = Baza + 1;    // +1 da ne ode iznad najvise tocke (vjerojatno ovisi i o debljini crte)
            while (y > MinY) {
                // crtica pored vrijednosti skale
                GrafickiObjekt.DrawLine(new Pen(Color.Black, 2),
                                        LijevaMargina + MARGINA_KOORDINATA - 10,
                                        y,
                                        LijevaMargina + MARGINA_KOORDINATA,
                                        y);

                // tanka linija na razini vrijednosti
                GrafickiObjekt.DrawLine(pen,
                                        LijevaMargina + MARGINA_KOORDINATA,
                                        y,
                                        SirinaOkvira,
                                        y);

                GrafickiObjekt.DrawString(Math.Round(vrijednostSkale, 1).ToString(),
                                          new Font(FontFamily.GenericSerif, 10),
                                          new SolidBrush(Color.Blue),
                                          new PointF(LijevaMargina + MARGINA_K_BROJEVA, y));
                y -= korak;
                vrijednostSkale += korakSkale;
            }

            if (Min < 0) {
                // y-koordinata ispod baze
                GrafickiObjekt.DrawLine(new Pen(Color.Black, 2),
                                        LijevaMargina + MARGINA_KOORDINATA,
                                        Baza,
                                        LijevaMargina + MARGINA_KOORDINATA,
                                        Baza + (Baza - MinY));

                // 0 je vec nacrtana pa pocinjemo od sljedeceg koraka
                vrijednostSkale = korakSkale;
                y = Baza - 1 + korak;      // -1 iz istog razloga kao i +1 gore
                while (y < Baza + (Baza - MinY)) {
                    // crtica pored vrijednosti skale
                    GrafickiObjekt.DrawLine(new Pen(Color.Black, 2),
                                            LijevaMargina + MARGINA_KOORDINATA - 10,
                                            y,
                                            LijevaMargina + MARGINA_KOORDINATA,
                                            y);

                    // tanka linija na razini vrijednosti
                    GrafickiObjekt.DrawLine(pen,
                                            LijevaMargina + MARGINA_KOORDINATA,
                                            y,
                                            SirinaOkvira,
                                            y);

                    GrafickiObjekt.DrawString(Math.Round(-vrijednostSkale, 1).ToString(),
                                              new Font(FontFamily.GenericSerif, 10),
                                              new SolidBrush(Color.Blue),
                                              new PointF(LijevaMargina + MARGINA_K_BROJEVA, y));
                    y += korak;
                    vrijednostSkale += korakSkale;
                }
            }
        }

        // ***** CLANSKE VARIJABLE *****

        protected List<Tuple<float, string>> Vrijednosti;
        protected float AbsMax;
        protected float Min;
        protected float Baza;
        protected int MinY;

        // ***** KONSTANTE *****
        public const int MARGINA_KOORDINATA = 40;
        public const int MARGINA_K_BROJEVA = MARGINA_KOORDINATA - 35;
    }
}
