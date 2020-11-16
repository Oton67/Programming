namespace WindowsFormsApp1 {
    partial class GlavnaForma {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing) {
            if (disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.Vrijednost = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Opis = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.groupBox_Kontrole = new System.Windows.Forms.GroupBox();
            this.button_Test = new System.Windows.Forms.Button();
            this.Button_Spremi = new System.Windows.Forms.Button();
            this.ComboBox_Format = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.groupBox_Kontrole.SuspendLayout();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Vrijednost,
            this.Opis});
            this.dataGridView1.Location = new System.Drawing.Point(6, 15);
            this.dataGridView1.Margin = new System.Windows.Forms.Padding(1, 1, 1, 1);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 37;
            this.dataGridView1.Size = new System.Drawing.Size(297, 286);
            this.dataGridView1.TabIndex = 0;
            // 
            // Vrijednost
            // 
            this.Vrijednost.HeaderText = "Vrijednost";
            this.Vrijednost.Name = "Vrijednost";
            // 
            // Opis
            // 
            this.Opis.HeaderText = "Opis";
            this.Opis.Name = "Opis";
            // 
            // groupBox_Kontrole
            // 
            this.groupBox_Kontrole.Controls.Add(this.ComboBox_Format);
            this.groupBox_Kontrole.Controls.Add(this.Button_Spremi);
            this.groupBox_Kontrole.Controls.Add(this.button_Test);
            this.groupBox_Kontrole.Controls.Add(this.dataGridView1);
            this.groupBox_Kontrole.Location = new System.Drawing.Point(335, 5);
            this.groupBox_Kontrole.Margin = new System.Windows.Forms.Padding(1, 1, 1, 1);
            this.groupBox_Kontrole.Name = "groupBox_Kontrole";
            this.groupBox_Kontrole.Padding = new System.Windows.Forms.Padding(1, 1, 1, 1);
            this.groupBox_Kontrole.Size = new System.Drawing.Size(343, 458);
            this.groupBox_Kontrole.TabIndex = 1;
            this.groupBox_Kontrole.TabStop = false;
            this.groupBox_Kontrole.Text = "Kontrole";
            // 
            // button_Test
            // 
            this.button_Test.Location = new System.Drawing.Point(260, 396);
            this.button_Test.Margin = new System.Windows.Forms.Padding(1, 1, 1, 1);
            this.button_Test.Name = "button_Test";
            this.button_Test.Size = new System.Drawing.Size(74, 32);
            this.button_Test.TabIndex = 1;
            this.button_Test.Text = "button1";
            this.button_Test.UseVisualStyleBackColor = true;
            this.button_Test.Click += new System.EventHandler(this.button_Test_Click);
            // 
            // Button_Spremi
            // 
            this.Button_Spremi.Location = new System.Drawing.Point(18, 401);
            this.Button_Spremi.Name = "Button_Spremi";
            this.Button_Spremi.Size = new System.Drawing.Size(75, 23);
            this.Button_Spremi.TabIndex = 2;
            this.Button_Spremi.Text = "button1";
            this.Button_Spremi.UseVisualStyleBackColor = true;
            this.Button_Spremi.Click += new System.EventHandler(this.Button_Spremi_Click);
            // 
            // ComboBox_Format
            // 
            this.ComboBox_Format.FormattingEnabled = true;
            this.ComboBox_Format.Items.AddRange(new object[] {
            "CSV",
            "XML"});
            this.ComboBox_Format.Location = new System.Drawing.Point(213, 325);
            this.ComboBox_Format.Name = "ComboBox_Format";
            this.ComboBox_Format.Size = new System.Drawing.Size(121, 21);
            this.ComboBox_Format.TabIndex = 3;
            // 
            // GlavnaForma
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(684, 468);
            this.Controls.Add(this.groupBox_Kontrole);
            this.Margin = new System.Windows.Forms.Padding(1, 1, 1, 1);
            this.Name = "GlavnaForma";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.groupBox_Kontrole.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.DataGridViewTextBoxColumn Vrijednost;
        private System.Windows.Forms.DataGridViewTextBoxColumn Opis;
        public System.Windows.Forms.GroupBox groupBox_Kontrole;
        private System.Windows.Forms.Button button_Test;
        private System.Windows.Forms.ComboBox ComboBox_Format;
        private System.Windows.Forms.Button Button_Spremi;
    }
}

