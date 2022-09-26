namespace WindowsFormsTP1
{
    partial class FormEje1
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
            this.label1 = new System.Windows.Forms.Label();
            this.txtAgregar = new System.Windows.Forms.TextBox();
            this.ListBoxPrincipio = new System.Windows.Forms.ListBox();
            this.ListBoxFinal = new System.Windows.Forms.ListBox();
            this.btnAgregar = new System.Windows.Forms.Button();
            this.btnPasarUno = new System.Windows.Forms.Button();
            this.btnPasarTodos = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(72, 50);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(153, 18);
            this.label1.TabIndex = 0;
            this.label1.Text = "Ingrese un nombre:";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // txtAgregar
            // 
            this.txtAgregar.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtAgregar.Location = new System.Drawing.Point(240, 50);
            this.txtAgregar.Name = "txtAgregar";
            this.txtAgregar.Size = new System.Drawing.Size(234, 24);
            this.txtAgregar.TabIndex = 1;
            // 
            // ListBoxPrincipio
            // 
            this.ListBoxPrincipio.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ListBoxPrincipio.FormattingEnabled = true;
            this.ListBoxPrincipio.ItemHeight = 18;
            this.ListBoxPrincipio.Location = new System.Drawing.Point(75, 158);
            this.ListBoxPrincipio.Name = "ListBoxPrincipio";
            this.ListBoxPrincipio.Size = new System.Drawing.Size(199, 202);
            this.ListBoxPrincipio.TabIndex = 2;
            // 
            // ListBoxFinal
            // 
            this.ListBoxFinal.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ListBoxFinal.FormattingEnabled = true;
            this.ListBoxFinal.ItemHeight = 18;
            this.ListBoxFinal.Location = new System.Drawing.Point(426, 158);
            this.ListBoxFinal.Name = "ListBoxFinal";
            this.ListBoxFinal.Size = new System.Drawing.Size(199, 202);
            this.ListBoxFinal.TabIndex = 3;
            // 
            // btnAgregar
            // 
            this.btnAgregar.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnAgregar.Location = new System.Drawing.Point(527, 47);
            this.btnAgregar.Name = "btnAgregar";
            this.btnAgregar.Size = new System.Drawing.Size(81, 33);
            this.btnAgregar.TabIndex = 4;
            this.btnAgregar.Text = "Agregar";
            this.btnAgregar.UseVisualStyleBackColor = true;
            this.btnAgregar.Click += new System.EventHandler(this.btnAgregar_Click);
            // 
            // btnPasarUno
            // 
            this.btnPasarUno.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnPasarUno.Location = new System.Drawing.Point(313, 216);
            this.btnPasarUno.Name = "btnPasarUno";
            this.btnPasarUno.Size = new System.Drawing.Size(75, 25);
            this.btnPasarUno.TabIndex = 5;
            this.btnPasarUno.Text = ">";
            this.btnPasarUno.UseVisualStyleBackColor = true;
            this.btnPasarUno.Click += new System.EventHandler(this.btnPasarUno_Click);
            // 
            // btnPasarTodos
            // 
            this.btnPasarTodos.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnPasarTodos.Location = new System.Drawing.Point(313, 273);
            this.btnPasarTodos.Name = "btnPasarTodos";
            this.btnPasarTodos.Size = new System.Drawing.Size(75, 26);
            this.btnPasarTodos.TabIndex = 6;
            this.btnPasarTodos.Text = ">>";
            this.btnPasarTodos.UseVisualStyleBackColor = true;
            this.btnPasarTodos.Click += new System.EventHandler(this.btnPasarTodos_Click);
            // 
            // FormEje1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(708, 458);
            this.Controls.Add(this.btnPasarTodos);
            this.Controls.Add(this.btnPasarUno);
            this.Controls.Add(this.btnAgregar);
            this.Controls.Add(this.ListBoxFinal);
            this.Controls.Add(this.ListBoxPrincipio);
            this.Controls.Add(this.txtAgregar);
            this.Controls.Add(this.label1);
            this.Name = "FormEje1";
            this.Text = "Ejercicio 1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtAgregar;
        private System.Windows.Forms.ListBox ListBoxPrincipio;
        private System.Windows.Forms.ListBox ListBoxFinal;
        private System.Windows.Forms.Button btnAgregar;
        private System.Windows.Forms.Button btnPasarUno;
        private System.Windows.Forms.Button btnPasarTodos;
    }
}