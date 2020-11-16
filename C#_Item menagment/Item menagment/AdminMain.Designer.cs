namespace Item_menagment
{
    partial class AdminMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(AdminMain));
            this.logout = new System.Windows.Forms.Button();
            this.AddItems = new System.Windows.Forms.TabPage();
            this.AddCategory = new System.Windows.Forms.Button();
            this.CategoryAdd = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.AddProduct = new System.Windows.Forms.Button();
            this.BrowseImage = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.Description = new System.Windows.Forms.TextBox();
            this.Stock = new System.Windows.Forms.TextBox();
            this.Price = new System.Windows.Forms.TextBox();
            this.ProdName = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.ManageUser = new System.Windows.Forms.TabPage();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.Home = new System.Windows.Forms.TabPage();
            this.RefreshData = new System.Windows.Forms.Button();
            this.Delete = new System.Windows.Forms.Button();
            this.Edit = new System.Windows.Forms.Button();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.tabControl = new System.Windows.Forms.TabControl();
            this.label13 = new System.Windows.Forms.Label();
            this.AddItems.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.ManageUser.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.Home.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            this.tabControl.SuspendLayout();
            this.SuspendLayout();
            // 
            // logout
            // 
            this.logout.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.logout.BackColor = System.Drawing.SystemColors.Window;
            this.logout.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.logout.ForeColor = System.Drawing.SystemColors.WindowFrame;
            this.logout.Location = new System.Drawing.Point(12, 475);
            this.logout.Name = "logout";
            this.logout.Size = new System.Drawing.Size(75, 23);
            this.logout.TabIndex = 0;
            this.logout.Text = "Logout";
            this.logout.UseVisualStyleBackColor = false;
            this.logout.Click += new System.EventHandler(this.Logout_Click);
            // 
            // AddItems
            // 
            this.AddItems.Controls.Add(this.AddCategory);
            this.AddItems.Controls.Add(this.CategoryAdd);
            this.AddItems.Controls.Add(this.label7);
            this.AddItems.Controls.Add(this.AddProduct);
            this.AddItems.Controls.Add(this.BrowseImage);
            this.AddItems.Controls.Add(this.pictureBox1);
            this.AddItems.Controls.Add(this.comboBox1);
            this.AddItems.Controls.Add(this.Description);
            this.AddItems.Controls.Add(this.Stock);
            this.AddItems.Controls.Add(this.Price);
            this.AddItems.Controls.Add(this.ProdName);
            this.AddItems.Controls.Add(this.label6);
            this.AddItems.Controls.Add(this.label5);
            this.AddItems.Controls.Add(this.label4);
            this.AddItems.Controls.Add(this.label3);
            this.AddItems.Controls.Add(this.label2);
            this.AddItems.Controls.Add(this.label1);
            this.AddItems.Location = new System.Drawing.Point(4, 29);
            this.AddItems.Name = "AddItems";
            this.AddItems.Padding = new System.Windows.Forms.Padding(3);
            this.AddItems.Size = new System.Drawing.Size(847, 424);
            this.AddItems.TabIndex = 2;
            this.AddItems.Text = "Add Items";
            this.AddItems.UseVisualStyleBackColor = true;
            // 
            // AddCategory
            // 
            this.AddCategory.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.AddCategory.BackColor = System.Drawing.SystemColors.ControlDark;
            this.AddCategory.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.AddCategory.ForeColor = System.Drawing.SystemColors.Window;
            this.AddCategory.Location = new System.Drawing.Point(713, 59);
            this.AddCategory.Name = "AddCategory";
            this.AddCategory.Size = new System.Drawing.Size(75, 30);
            this.AddCategory.TabIndex = 15;
            this.AddCategory.Text = "Add";
            this.AddCategory.UseVisualStyleBackColor = false;
            this.AddCategory.Click += new System.EventHandler(this.AddCategory_Click);
            // 
            // CategoryAdd
            // 
            this.CategoryAdd.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.CategoryAdd.Location = new System.Drawing.Point(688, 21);
            this.CategoryAdd.Name = "CategoryAdd";
            this.CategoryAdd.Size = new System.Drawing.Size(100, 26);
            this.CategoryAdd.TabIndex = 14;
            // 
            // label7
            // 
            this.label7.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(570, 24);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(112, 20);
            this.label7.TabIndex = 13;
            this.label7.Text = "New Category:";
            // 
            // AddProduct
            // 
            this.AddProduct.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.AddProduct.BackColor = System.Drawing.SystemColors.ControlDark;
            this.AddProduct.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.AddProduct.ForeColor = System.Drawing.SystemColors.Window;
            this.AddProduct.Location = new System.Drawing.Point(758, 386);
            this.AddProduct.Name = "AddProduct";
            this.AddProduct.Size = new System.Drawing.Size(83, 32);
            this.AddProduct.TabIndex = 12;
            this.AddProduct.Text = "Add Item";
            this.AddProduct.UseVisualStyleBackColor = false;
            this.AddProduct.Click += new System.EventHandler(this.AddProduct_Click);
            // 
            // BrowseImage
            // 
            this.BrowseImage.BackColor = System.Drawing.SystemColors.ControlDark;
            this.BrowseImage.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.BrowseImage.ForeColor = System.Drawing.SystemColors.Window;
            this.BrowseImage.Location = new System.Drawing.Point(314, 269);
            this.BrowseImage.Name = "BrowseImage";
            this.BrowseImage.Size = new System.Drawing.Size(72, 31);
            this.BrowseImage.TabIndex = 11;
            this.BrowseImage.Text = "Browse";
            this.BrowseImage.UseVisualStyleBackColor = false;
            this.BrowseImage.Click += new System.EventHandler(this.BrowseImage_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(155, 188);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(153, 112);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 10;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Click += new System.EventHandler(this.BrowseImage_Click);
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(155, 64);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(121, 28);
            this.comboBox1.TabIndex = 9;
            // 
            // Description
            // 
            this.Description.Location = new System.Drawing.Point(155, 316);
            this.Description.Multiline = true;
            this.Description.Name = "Description";
            this.Description.Size = new System.Drawing.Size(245, 102);
            this.Description.TabIndex = 8;
            // 
            // Stock
            // 
            this.Stock.Location = new System.Drawing.Point(155, 147);
            this.Stock.Name = "Stock";
            this.Stock.Size = new System.Drawing.Size(121, 26);
            this.Stock.TabIndex = 7;
            this.Stock.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.Number_KeyPress);
            // 
            // Price
            // 
            this.Price.Location = new System.Drawing.Point(155, 106);
            this.Price.Name = "Price";
            this.Price.Size = new System.Drawing.Size(121, 26);
            this.Price.TabIndex = 6;
            this.Price.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.Number_KeyPress);
            // 
            // ProdName
            // 
            this.ProdName.Location = new System.Drawing.Point(153, 21);
            this.ProdName.Name = "ProdName";
            this.ProdName.Size = new System.Drawing.Size(123, 26);
            this.ProdName.TabIndex = 5;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(76, 67);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(73, 20);
            this.label6.TabIndex = 4;
            this.label6.Text = "Category";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(64, 392);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(89, 20);
            this.label5.TabIndex = 3;
            this.label5.Text = "Description";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(99, 274);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(54, 20);
            this.label4.TabIndex = 2;
            this.label4.Text = "Image";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(99, 150);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(50, 20);
            this.label3.TabIndex = 1;
            this.label3.Text = "Stock";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(105, 109);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(44, 20);
            this.label2.TabIndex = 1;
            this.label2.Text = "Price";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(39, 24);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(110, 20);
            this.label1.TabIndex = 0;
            this.label1.Text = "Product Name";
            // 
            // ManageUser
            // 
            this.ManageUser.Controls.Add(this.dataGridView1);
            this.ManageUser.Location = new System.Drawing.Point(4, 29);
            this.ManageUser.Name = "ManageUser";
            this.ManageUser.Padding = new System.Windows.Forms.Padding(3);
            this.ManageUser.Size = new System.Drawing.Size(847, 424);
            this.ManageUser.TabIndex = 1;
            this.ManageUser.Text = "Manage Users";
            this.ManageUser.UseVisualStyleBackColor = true;
            // 
            // dataGridView1
            // 
            this.dataGridView1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dataGridView1.BackgroundColor = System.Drawing.SystemColors.Window;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(6, 6);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(835, 412);
            this.dataGridView1.TabIndex = 2;
            this.dataGridView1.RowHeaderMouseClick += new System.Windows.Forms.DataGridViewCellMouseEventHandler(this.DataGridView1_RowHeaderMouseClick);
            // 
            // Home
            // 
            this.Home.Controls.Add(this.RefreshData);
            this.Home.Controls.Add(this.Delete);
            this.Home.Controls.Add(this.Edit);
            this.Home.Controls.Add(this.dataGridView2);
            this.Home.Location = new System.Drawing.Point(4, 29);
            this.Home.Name = "Home";
            this.Home.Padding = new System.Windows.Forms.Padding(3);
            this.Home.Size = new System.Drawing.Size(847, 424);
            this.Home.TabIndex = 0;
            this.Home.Text = "Manage Items";
            this.Home.UseVisualStyleBackColor = true;
            // 
            // RefreshData
            // 
            this.RefreshData.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.RefreshData.BackColor = System.Drawing.SystemColors.ControlDark;
            this.RefreshData.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.RefreshData.ForeColor = System.Drawing.SystemColors.Window;
            this.RefreshData.Location = new System.Drawing.Point(769, 394);
            this.RefreshData.Name = "RefreshData";
            this.RefreshData.Size = new System.Drawing.Size(75, 27);
            this.RefreshData.TabIndex = 3;
            this.RefreshData.Text = "Refresh";
            this.RefreshData.UseVisualStyleBackColor = false;
            this.RefreshData.Click += new System.EventHandler(this.RefreshData_Click);
            // 
            // Delete
            // 
            this.Delete.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.Delete.BackColor = System.Drawing.SystemColors.ControlDark;
            this.Delete.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.Delete.ForeColor = System.Drawing.SystemColors.Window;
            this.Delete.Location = new System.Drawing.Point(87, 394);
            this.Delete.Name = "Delete";
            this.Delete.Size = new System.Drawing.Size(75, 27);
            this.Delete.TabIndex = 2;
            this.Delete.Text = "Delete";
            this.Delete.UseVisualStyleBackColor = false;
            this.Delete.Click += new System.EventHandler(this.Delete_Click);
            // 
            // Edit
            // 
            this.Edit.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.Edit.BackColor = System.Drawing.SystemColors.ControlDark;
            this.Edit.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.Edit.ForeColor = System.Drawing.SystemColors.Window;
            this.Edit.Location = new System.Drawing.Point(6, 394);
            this.Edit.Name = "Edit";
            this.Edit.Size = new System.Drawing.Size(75, 27);
            this.Edit.TabIndex = 1;
            this.Edit.Text = "Edit";
            this.Edit.UseVisualStyleBackColor = false;
            this.Edit.Click += new System.EventHandler(this.Edit_Click);
            // 
            // dataGridView2
            // 
            this.dataGridView2.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dataGridView2.BackgroundColor = System.Drawing.SystemColors.Window;
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Location = new System.Drawing.Point(6, 6);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.Size = new System.Drawing.Size(835, 382);
            this.dataGridView2.TabIndex = 0;
            this.dataGridView2.RowHeaderMouseClick += new System.Windows.Forms.DataGridViewCellMouseEventHandler(this.dataGridView2_RowHeaderMouseClick);
            // 
            // tabControl
            // 
            this.tabControl.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tabControl.Controls.Add(this.Home);
            this.tabControl.Controls.Add(this.ManageUser);
            this.tabControl.Controls.Add(this.AddItems);
            this.tabControl.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tabControl.Location = new System.Drawing.Point(12, 12);
            this.tabControl.Name = "tabControl";
            this.tabControl.SelectedIndex = 0;
            this.tabControl.Size = new System.Drawing.Size(855, 457);
            this.tabControl.TabIndex = 1;
            // 
            // label13
            // 
            this.label13.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.label13.AutoSize = true;
            this.label13.BackColor = System.Drawing.Color.Transparent;
            this.label13.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label13.ForeColor = System.Drawing.SystemColors.Window;
            this.label13.Location = new System.Drawing.Point(735, 481);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(132, 20);
            this.label13.TabIndex = 16;
            this.label13.Text = "Welcome,  Admin";
            // 
            // AdminMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ButtonShadow;
            this.ClientSize = new System.Drawing.Size(879, 510);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.tabControl);
            this.Controls.Add(this.logout);
            this.Name = "AdminMain";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "AdminMain";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.AdminMain_FormClosed);
            this.Load += new System.EventHandler(this.AdminMain_Load);
            this.AddItems.ResumeLayout(false);
            this.AddItems.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ManageUser.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.Home.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            this.tabControl.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button logout;
     /*   private System.Windows.Forms.BindingSource testloginDataSetBindingSource;
       // private testloginDataSet testloginDataSet;
        private System.Windows.Forms.BindingSource testloginDataSetBindingSource2;
        private System.Windows.Forms.BindingSource testloginDataSetBindingSource1;
       // private testloginDataSet1 testloginDataSet1;
        private System.Windows.Forms.BindingSource loginBindingSource;
      //  private testloginDataSet1TableAdapters.loginTableAdapter loginTableAdapter;
      //  private testloginDataSet1TableAdapters.loginTableAdapter loginTableAdapter1;
      //  private testloginDataSet2 testloginDataSet2;
        private System.Windows.Forms.BindingSource addItemBindingSource;
     */ //  private testloginDataSet2TableAdapters.AddItemTableAdapter addItemTableAdapter;
        private System.Windows.Forms.TabPage AddItems;
        private System.Windows.Forms.Button AddProduct;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.TextBox Description;
        private System.Windows.Forms.TextBox Stock;
        private System.Windows.Forms.TextBox Price;
        private System.Windows.Forms.TextBox ProdName;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TabPage ManageUser;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.TabPage Home;
        private System.Windows.Forms.Button Delete;
        private System.Windows.Forms.Button Edit;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.TabControl tabControl;
        private System.Windows.Forms.Button RefreshData;
        private System.Windows.Forms.Button AddCategory;
        private System.Windows.Forms.TextBox CategoryAdd;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button BrowseImage;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label13;
    }
}