
namespace TP1
{
    partial class FormEj3
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
            this.chlbOficios = new System.Windows.Forms.CheckedListBox();
            this.gbEstadoCivil = new System.Windows.Forms.GroupBox();
            this.btnSoltero = new System.Windows.Forms.RadioButton();
            this.btnCasado = new System.Windows.Forms.RadioButton();
            this.gbSexo = new System.Windows.Forms.GroupBox();
            this.btnMasculino = new System.Windows.Forms.RadioButton();
            this.btnFemenino = new System.Windows.Forms.RadioButton();
            this.btnMostrar = new System.Windows.Forms.Button();
            this.btnMenuPrincipal = new System.Windows.Forms.Button();
            this.lbElementosSeleccionados = new System.Windows.Forms.Label();
            this.gbEstadoCivil.SuspendLayout();
            this.gbSexo.SuspendLayout();
            this.SuspendLayout();
            // 
            // chlbOficios
            // 
            this.chlbOficios.CheckOnClick = true;
            this.chlbOficios.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.chlbOficios.FormattingEnabled = true;
            this.chlbOficios.Items.AddRange(new object[] {
            "Data Entry",
            "Operador de PC",
            "Programador",
            "Reparador de PC",
            "Tester"});
            this.chlbOficios.Location = new System.Drawing.Point(300, 110);
            this.chlbOficios.Name = "chlbOficios";
            this.chlbOficios.Size = new System.Drawing.Size(187, 109);
            this.chlbOficios.TabIndex = 0;
            // 
            // gbEstadoCivil
            // 
            this.gbEstadoCivil.Controls.Add(this.btnSoltero);
            this.gbEstadoCivil.Controls.Add(this.btnCasado);
            this.gbEstadoCivil.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gbEstadoCivil.Location = new System.Drawing.Point(511, 9);
            this.gbEstadoCivil.Name = "gbEstadoCivil";
            this.gbEstadoCivil.Size = new System.Drawing.Size(200, 100);
            this.gbEstadoCivil.TabIndex = 1;
            this.gbEstadoCivil.TabStop = false;
            this.gbEstadoCivil.Text = "Estado Civil";
            // 
            // btnSoltero
            // 
            this.btnSoltero.AutoSize = true;
            this.btnSoltero.Location = new System.Drawing.Point(19, 63);
            this.btnSoltero.Name = "btnSoltero";
            this.btnSoltero.Size = new System.Drawing.Size(65, 17);
            this.btnSoltero.TabIndex = 0;
            this.btnSoltero.Text = "Soltero";
            this.btnSoltero.UseVisualStyleBackColor = true;
            this.btnSoltero.CheckedChanged += new System.EventHandler(this.btnSoltero_CheckedChanged);
            // 
            // btnCasado
            // 
            this.btnCasado.AutoSize = true;
            this.btnCasado.Checked = true;
            this.btnCasado.Location = new System.Drawing.Point(19, 31);
            this.btnCasado.Name = "btnCasado";
            this.btnCasado.Size = new System.Drawing.Size(67, 17);
            this.btnCasado.TabIndex = 0;
            this.btnCasado.TabStop = true;
            this.btnCasado.Text = "Casado";
            this.btnCasado.UseVisualStyleBackColor = true;
            this.btnCasado.CheckedChanged += new System.EventHandler(this.btnCasado_CheckedChanged);
            // 
            // gbSexo
            // 
            this.gbSexo.Controls.Add(this.btnMasculino);
            this.gbSexo.Controls.Add(this.btnFemenino);
            this.gbSexo.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gbSexo.Location = new System.Drawing.Point(73, 9);
            this.gbSexo.Name = "gbSexo";
            this.gbSexo.Size = new System.Drawing.Size(200, 100);
            this.gbSexo.TabIndex = 2;
            this.gbSexo.TabStop = false;
            this.gbSexo.Text = "Sexo";
            // 
            // btnMasculino
            // 
            this.btnMasculino.AutoSize = true;
            this.btnMasculino.Location = new System.Drawing.Point(21, 63);
            this.btnMasculino.Name = "btnMasculino";
            this.btnMasculino.Size = new System.Drawing.Size(82, 17);
            this.btnMasculino.TabIndex = 0;
            this.btnMasculino.Text = "Masculino";
            this.btnMasculino.UseVisualStyleBackColor = true;
            this.btnMasculino.CheckedChanged += new System.EventHandler(this.btnMasculino_CheckedChanged);
            // 
            // btnFemenino
            // 
            this.btnFemenino.AutoSize = true;
            this.btnFemenino.Checked = true;
            this.btnFemenino.Location = new System.Drawing.Point(21, 31);
            this.btnFemenino.Name = "btnFemenino";
            this.btnFemenino.Size = new System.Drawing.Size(79, 17);
            this.btnFemenino.TabIndex = 0;
            this.btnFemenino.TabStop = true;
            this.btnFemenino.Text = "Femenino";
            this.btnFemenino.UseVisualStyleBackColor = true;
            this.btnFemenino.CheckedChanged += new System.EventHandler(this.btnFemenino_CheckedChanged);
            // 
            // btnMostrar
            // 
            this.btnMostrar.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnMostrar.Location = new System.Drawing.Point(300, 238);
            this.btnMostrar.Name = "btnMostrar";
            this.btnMostrar.Size = new System.Drawing.Size(187, 23);
            this.btnMostrar.TabIndex = 3;
            this.btnMostrar.Text = "Mostrar lo que se selecciono";
            this.btnMostrar.UseVisualStyleBackColor = true;
            this.btnMostrar.Click += new System.EventHandler(this.btnMostrar_Click);
            // 
            // btnMenuPrincipal
            // 
            this.btnMenuPrincipal.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnMenuPrincipal.Location = new System.Drawing.Point(300, 40);
            this.btnMenuPrincipal.Name = "btnMenuPrincipal";
            this.btnMenuPrincipal.Size = new System.Drawing.Size(187, 43);
            this.btnMenuPrincipal.TabIndex = 9;
            this.btnMenuPrincipal.Text = "Menu Principal";
            this.btnMenuPrincipal.UseVisualStyleBackColor = true;
            this.btnMenuPrincipal.Click += new System.EventHandler(this.btnMenuPrincipal_Click);
            // 
            // lbElementosSeleccionados
            // 
            this.lbElementosSeleccionados.AutoSize = true;
            this.lbElementosSeleccionados.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbElementosSeleccionados.Location = new System.Drawing.Point(237, 279);
            this.lbElementosSeleccionados.Name = "lbElementosSeleccionados";
            this.lbElementosSeleccionados.Size = new System.Drawing.Size(51, 15);
            this.lbElementosSeleccionados.TabIndex = 10;
            this.lbElementosSeleccionados.Text = "TEXTO";
            this.lbElementosSeleccionados.Visible = false;
            // 
            // FormEj3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.lbElementosSeleccionados);
            this.Controls.Add(this.btnMenuPrincipal);
            this.Controls.Add(this.btnMostrar);
            this.Controls.Add(this.gbSexo);
            this.Controls.Add(this.gbEstadoCivil);
            this.Controls.Add(this.chlbOficios);
            this.Name = "FormEj3";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "FormEj3";
            this.gbEstadoCivil.ResumeLayout(false);
            this.gbEstadoCivil.PerformLayout();
            this.gbSexo.ResumeLayout(false);
            this.gbSexo.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckedListBox chlbOficios;
        private System.Windows.Forms.GroupBox gbEstadoCivil;
        private System.Windows.Forms.GroupBox gbSexo;
        private System.Windows.Forms.Button btnMostrar;
        private System.Windows.Forms.RadioButton btnSoltero;
        private System.Windows.Forms.RadioButton btnCasado;
        private System.Windows.Forms.RadioButton btnMasculino;
        private System.Windows.Forms.RadioButton btnFemenino;
        private System.Windows.Forms.Button btnMenuPrincipal;
        private System.Windows.Forms.Label lbElementosSeleccionados;
    }
}