using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace WindowsFormsApp1 {
    public partial class GlavnaForma : Form {
        public GlavnaForma() {
            InitializeComponent();
        }

        //private Grafikon _Graf;

        private List<Tuple<float, string>> _ProcitajVrijednosti()
        {
            var Vrijednosti = new List<Tuple<float, string>>();
            DataGridViewRowCollection retci = dataGridView1.Rows;
            foreach (DataGridViewRow redak in retci)
            {
                if (redak.Cells[0].Value == null && redak.Cells[1].Value == null) break;

                float v = redak.Cells[0].Value == null ? 0 : float.Parse(redak.Cells[0].Value.ToString());

                string opis = redak.Cells[1].Value == null ? "" : redak.Cells[1].Value.ToString();
                Vrijednosti.Add(Tuple.Create(v, opis));
            }
            return Vrijednosti;
        }

        private void button_Test_Click(object sender, EventArgs e) {
           /* var v = new List<Tuple<float, string>> {
                Tuple.Create((float)12.0, ""),
                Tuple.Create((float)-42.0, ""),
                Tuple.Create((float)8.0, ""),
                Tuple.Create((float)19.0, ""),
                Tuple.Create((float)-11.0, ""),
                Tuple.Create((float)40.0, ""),
            };*/

            Grafikon g = new StupcaniGrafikon(this, _ProcitajVrijednosti());
            g.Prikazi();
        }

        private void Button_Spremi_Click(object sender, EventArgs e)
        {
            var vrijdnosti = _ProcitajVrijednosti();

            var dlg = new SaveFileDialog();
            dlg.ShowDialog();
            if (dlg.FileName == "")
            {
                return;
            }

            switch (ComboBox_Format.Text)
            {
                case "XML": break;

                case "CSV": break;

                default:
                    MessageBox.Show("Odaberite format:");
                    break;
            }
        }
    }
}
