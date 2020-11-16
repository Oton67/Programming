using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Configuration;
using System.Timers;
using System.Diagnostics;

namespace Item_menagment
{

    public partial class AdminMain : Form 
    {
        string connection = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=|DataDirectory|testlogin.mdf;Integrated Security=True;Connect Timeout=30";

        SqlCommand cmd;
        int ID = 0;

        public AdminMain()
        {
            InitializeComponent();
            this.dataGridView2.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.DisplayedCells;
            this.dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.DisplayedCells;

            dataGridView2.RowTemplate.Height = 60;

            dataGridView1.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            dataGridView2.SelectionMode = DataGridViewSelectionMode.FullRowSelect;

            using (SqlConnection sqlCon = new SqlConnection(connection))
            {
                sqlCon.Open();

                string category;
                string value;
                int flag = 0;
                SqlCommand oCmd = new SqlCommand("SELECT ItemCatagory from AddItem", sqlCon);
                using (SqlDataReader oReader = oCmd.ExecuteReader())
                {
                    while (oReader.Read())
                    {
                        category = (oReader["ItemCatagory"]).ToString();
                        for (int i = 0; i < comboBox1.Items.Count; i++)
                        {
                            value = comboBox1.GetItemText(comboBox1.Items[i]);
                            if (value == category || category == "Other") flag = 1;
                        }
                        if (flag == 0) comboBox1.Items.Add(category);
                        flag = 0;

                    }
                    comboBox1.Items.Add("Other");

                }
            }
        }

        private void AdminMain_FormClosed(object sender, FormClosedEventArgs e)
        {
            //Process.GetCurrentProcess().Kill();
            Application.Exit();
        }


        private void Logout_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form1 login = new Form1();
            login.Show();
        }

        private void ItemLoad()
        {
            using (SqlConnection sqlCon = new SqlConnection(connection))
            {
                sqlCon.Open();
                SqlDataAdapter sqlDa = new SqlDataAdapter("SELECT * FROM AddItem", sqlCon);
                DataTable dtbl = new DataTable();
                sqlDa.Fill(dtbl);

                dataGridView2.DataSource = dtbl;


                for (int i = 0; i < dataGridView2.Columns.Count; i++)
                    if (dataGridView2.Columns[i] is DataGridViewImageColumn)
                    {
                        ((DataGridViewImageColumn)dataGridView2.Columns[i]).ImageLayout = DataGridViewImageCellLayout.Stretch;
                        ((DataGridViewImageColumn)dataGridView2.Columns[i]).Width = 100;
                        ((DataGridViewImageColumn)dataGridView2.Columns[i]).DefaultCellStyle.NullValue = null;
                        ((DataGridViewImageColumn)dataGridView2.Columns[i]).AutoSizeMode = DataGridViewAutoSizeColumnMode.None;
                        break;
                    }
                dataGridView2.Columns[6].Width = 250;
                dataGridView2.Columns[6].DefaultCellStyle.WrapMode = DataGridViewTriState.True;
                dataGridView2.Columns[6].AutoSizeMode = DataGridViewAutoSizeColumnMode.None;
            }
         }

        private void AdminMain_Load(object sender, EventArgs e)
        {
            //dataGridView2.AutoResizeColumns();
            dataGridView1.ReadOnly = true;
            dataGridView2.ReadOnly = true;

            ItemLoad();

            using (SqlConnection sqlCon = new SqlConnection(connection))
            {
                
                SqlDataAdapter UsersqlDa = new SqlDataAdapter("SELECT * FROM login", sqlCon);
                DataTable Userdtbl = new DataTable();
                UsersqlDa.Fill(Userdtbl);

                dataGridView1.DataSource = Userdtbl;
            }
        }

        private void BrowseImage_Click(object sender, EventArgs e)
        {
            OpenFileDialog opf = new OpenFileDialog();
            opf.Filter = "Choose Image(*.jpg;*.png;*.gif)|*.jpg;*.png;*.gif";

            if (opf.ShowDialog() == DialogResult.OK)
            {
                pictureBox1.Image = Image.FromFile(opf.FileName);
            }
        }

        private void AddProduct_Click(object sender, EventArgs e)
        {
            ImageConverter imgc = new ImageConverter();
            byte[] img = (byte[])imgc.ConvertTo(pictureBox1.Image, Type.GetType("System.Byte[]"));

            using (SqlConnection sqlCon = new SqlConnection(connection))
            {
                sqlCon.Open();
                SqlCommand sqlCmd = new SqlCommand("ItemAdd", sqlCon);
                sqlCmd.CommandType = CommandType.StoredProcedure;
                sqlCmd.Parameters.AddWithValue("@ItemName", ProdName.Text.Trim());
                sqlCmd.Parameters.AddWithValue("@ItemCatagory", comboBox1.Text.Trim());
                sqlCmd.Parameters.AddWithValue("@ItemPrice", Price.Text.Trim());
                sqlCmd.Parameters.AddWithValue("@ItemStock", Stock.Text.Trim());
                sqlCmd.Parameters.AddWithValue("@ItemImage", img);
                sqlCmd.Parameters.AddWithValue("@ItemDescription", Description.Text.Trim());
                sqlCmd.ExecuteNonQuery();

                MessageBox.Show("Item Added!");
                Clear();

                dataGridView2.DataSource = null;
                ItemLoad();
            }

        }

        public void UserRefrash()
        {
            using (SqlConnection sqlCon = new SqlConnection(connection))
            {

                dataGridView1.DataSource = null;
                SqlDataAdapter UsersqlDa = new SqlDataAdapter("SELECT * FROM login", sqlCon);
                DataTable Userdtbl = new DataTable();
                UsersqlDa.Fill(Userdtbl);

                dataGridView1.DataSource = Userdtbl;
            }
        }

        void Clear()
        {
            ProdName.Text = comboBox1.Text = Price.Text = Stock.Text = Description.Text = "";
            pictureBox1.Image = null;
        }

        private void Edit_Click(object sender, EventArgs e)
        {
            EditItems Edit = new EditItems();
            Edit.Show();
        }



        private void dataGridView2_RowHeaderMouseClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            //MessageBox.Show(dataGridView2.Rows[e.RowIndex].Cells[0].Value.ToString());
            ID = Convert.ToInt32(dataGridView2.Rows[e.RowIndex].Cells[0].Value.ToString());
            //ItemName = dataGridView2.Rows[e.RowIndex].Cells[1].Value.ToString();
            //ItemCatagory = dataGridView2.Rows[e.RowIndex].Cells[2].Value.ToString();
            //ItemPrice = Convert.ToDouble(dataGridView2.Rows[e.RowIndex].Cells[3].Value.ToString());
            //ItemStock = Convert.ToInt32(dataGridView2.Rows[e.RowIndex].Cells[4].Value.ToString());
            //ItemDescription = dataGridView2.Rows[e.RowIndex].Cells[6].Value.ToString();

        }


        private void Delete_Click(object sender, EventArgs e)
        {

            using (SqlConnection sqlCon = new SqlConnection(connection))
            {
                if (ID != 0)
                {
                    sqlCon.Open();
                    cmd = new SqlCommand("DELETE FROM AddItem WHERE ItemID= '" + ID + "';", sqlCon);
                    //cmd.Parameters.AddWithValue("@ItemID", ID);
                    cmd.ExecuteNonQuery();
                    MessageBox.Show("Record Deleted Successfully!");

                    dataGridView2.DataSource = null;
                    ItemLoad();

                    ID = 0;
                }

                for (int i = 0; i < dataGridView2.Columns.Count; i++)
                    if (dataGridView2.Columns[i] is DataGridViewImageColumn)
                    {
                        ((DataGridViewImageColumn)dataGridView2.Columns[i]).ImageLayout = DataGridViewImageCellLayout.Stretch;
                        break;
                    }

            }
        }


        private void RefreshData_Click(object sender, EventArgs e)
        {
            dataGridView2.DataSource = null;
            ItemLoad();
        }

        private void Number_KeyPress(object sender, KeyPressEventArgs e)
        {
            Char chr = e.KeyChar;
            if (!Char.IsDigit(chr))
            {
                e.Handled = true;
                MessageBox.Show("Please enter a valid value!");
            }
        }

        private void DataGridView1_RowHeaderMouseClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            int UserID = Convert.ToInt32(dataGridView1.Rows[e.RowIndex].Cells[0].Value.ToString());

            string UserFirstName = dataGridView1.Rows[e.RowIndex].Cells[3].Value.ToString();
            string UserLastName = dataGridView1.Rows[e.RowIndex].Cells[4].Value.ToString();
            string UserEmail = dataGridView1.Rows[e.RowIndex].Cells[5].Value.ToString();
            string UserContact = dataGridView1.Rows[e.RowIndex].Cells[6].Value.ToString();
            string UserUsername = dataGridView1.Rows[e.RowIndex].Cells[1].Value.ToString();
            string UserPassword = dataGridView1.Rows[e.RowIndex].Cells[2].Value.ToString();

            UserEdit U = new UserEdit(UserID, UserFirstName, UserLastName, UserEmail, UserContact, UserUsername, UserPassword);
            U.Show();
            U.FormClosed += (o, i) => { UserRefrash(); };
        }

        private void AddCategory_Click(object sender, EventArgs e)
        {
            comboBox1.Items.Add(CategoryAdd.Text);
            MessageBox.Show("Category added!");
        }
    }

        

}
