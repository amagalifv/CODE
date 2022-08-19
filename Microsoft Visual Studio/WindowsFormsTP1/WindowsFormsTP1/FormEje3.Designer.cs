namespace WindowsFormsTP1
{
    partial class FormEje3
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
            this.grpBoxSexo = new System.Windows.Forms.GroupBox();
            this.grpBoxEstCiv = new System.Windows.Forms.GroupBox();
            this.radioBtnFem = new System.Windows.Forms.RadioButton();
            this.radioBntMasc = new System.Windows.Forms.RadioButton();
            this.radioBtnCasado = new System.Windows.Forms.RadioButton();
            this.radioBtnSolt = new System.Windows.Forms.RadioButton();
            this.checkedListBox = new System.Windows.Forms.CheckedListBox();
            this.btnMostrar = new System.Windows.Forms.Button();
            this.lblHeader = new System.Windows.Forms.Label();
            this.lblElemSelec = new System.Windows.Forms.Label();
            this.grpBoxSexo.SuspendLayout();
            this.grpBoxEstCiv.SuspendLayout();
            this.SuspendLayout();
            // 
            // grpBoxSexo
            // 
            this.grpBoxSexo.Controls.Add(this.radioBtnFem);
            this.grpBoxSexo.Controls.Add(this.radioBntMasc);
            this.grpBoxSexo.Location = new System.Drawing.Point(125, 12);
            this.grpBoxSexo.Name = "grpBoxSexo";
            this.grpBoxSexo.Size = new System.Drawing.Size(166, 100);
            this.grpBoxSexo.TabIndex = 0;
            this.grpBoxSexo.TabStop = false;
            this.grpBoxSexo.Text = "Sexo";
            // 
            // grpBoxEstCiv
            // 
            this.grpBoxEstCiv.Controls.Add(this.radioBtnSolt);
            this.grpBoxEstCiv.Controls.Add(this.radioBtnCasado);
            this.grpBoxEstCiv.Location = new System.Drawing.Point(474, 12);
            this.grpBoxEstCiv.Name = "grpBoxEstCiv";
            this.grpBoxEstCiv.Size = new System.Drawing.Size(169, 100);
            this.grpBoxEstCiv.TabIndex = 1;
            this.grpBoxEstCiv.TabStop = false;
            this.grpBoxEstCiv.Text = "Estado Civil";
            // 
            // radioBtnFem
            // 
            this.radioBtnFem.AutoSize = true;
            this.radioBtnFem.Checked = true;
            this.radioBtnFem.Location = new System.Drawing.Point(39, 28);
            this.radioBtnFem.Name = "radioBtnFem";
            this.radioBtnFem.Size = new System.Drawing.Size(71, 17);
            this.radioBtnFem.TabIndex = 2;
            this.radioBtnFem.TabStop = true;
            this.radioBtnFem.Text = "Femenino";
            this.radioBtnFem.UseVisualStyleBackColor = true;
            // 
            // radioBntMasc
            // 
            this.radioBntMasc.AutoSize = true;
            this.radioBntMasc.Location = new System.Drawing.Point(39, 51);
            this.radioBntMasc.Name = "radioBntMasc";
            this.radioBntMasc.Size = new System.Drawing.Size(73, 17);
            this.radioBntMasc.TabIndex = 3;
            this.radioBntMasc.Text = "Masculino";
            this.radioBntMasc.UseVisualStyleBackColor = true;
            // 
            // radioBtnCasado
            // 
            this.radioBtnCasado.AutoSize = true;
            this.radioBtnCasado.Checked = true;
            this.radioBtnCasado.Location = new System.Drawing.Point(39, 28);
            this.radioBtnCasado.Name = "radioBtnCasado";
            this.radioBtnCasado.Size = new System.Drawing.Size(61, 17);
            this.radioBtnCasado.TabIndex = 4;
            this.radioBtnCasado.TabStop = true;
            this.radioBtnCasado.Text = "Casado";
            this.radioBtnCasado.UseVisualStyleBackColor = true;
            // 
            // radioBtnSolt
            // 
            this.radioBtnSolt.AutoSize = true;
            this.radioBtnSolt.Location = new System.Drawing.Point(39, 51);
            this.radioBtnSolt.Name = "radioBtnSolt";
            this.radioBtnSolt.Size = new System.Drawing.Size(58, 17);
            this.radioBtnSolt.TabIndex = 5;
            this.radioBtnSolt.Text = "Soltero";
            this.radioBtnSolt.UseVisualStyleBackColor = true;
            // 
            // checkedListBox
            // 
            this.checkedListBox.FormattingEnabled = true;
            this.checkedListBox.Items.AddRange(new object[] {
            "Data Entry",
            "Operador de PC",
            "Programador",
            "Reparador de PC",
            "Tester"});
            this.checkedListBox.Location = new System.Drawing.Point(324, 108);
            this.checkedListBox.Name = "checkedListBox";
            this.checkedListBox.Size = new System.Drawing.Size(120, 94);
            this.checkedListBox.TabIndex = 2;
            // 
            // btnMostrar
            // 
            this.btnMostrar.Location = new System.Drawing.Point(324, 208);
            this.btnMostrar.Name = "btnMostrar";
            this.btnMostrar.Size = new System.Drawing.Size(120, 35);
            this.btnMostrar.TabIndex = 3;
            this.btnMostrar.Text = "Mostrar lo seleccionado";
            this.btnMostrar.UseVisualStyleBackColor = true;
            this.btnMostrar.Click += new System.EventHandler(this.btnMostrar_Click);
            // 
            // lblHeader
            // 
            this.lblHeader.AutoSize = true;
            this.lblHeader.Location = new System.Drawing.Point(122, 260);
            this.lblHeader.Name = "lblHeader";
            this.lblHeader.Size = new System.Drawing.Size(126, 13);
            this.lblHeader.TabIndex = 4;
            this.lblHeader.Text = "Elementos Selecionados:";
            this.lblHeader.Visible = false;
            // 
            // lblElemSelec
            // 
            this.lblElemSelec.AutoSize = true;
            this.lblElemSelec.Location = new System.Drawing.Point(122, 294);
            this.lblElemSelec.Name = "lblElemSelec";
            this.lblElemSelec.Size = new System.Drawing.Size(35, 13);
            this.lblElemSelec.TabIndex = 5;
            this.lblElemSelec.Text = "label2";
            this.lblElemSelec.Visible = false;
            // 
            // FormEje3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(783, 452);
            this.Controls.Add(this.lblElemSelec);
            this.Controls.Add(this.lblHeader);
            this.Controls.Add(this.btnMostrar);
            this.Controls.Add(this.checkedListBox);
            this.Controls.Add(this.grpBoxEstCiv);
            this.Controls.Add(this.grpBoxSexo);
            this.Name = "FormEje3";
            this.Text = "Ejercicio 3";
            this.grpBoxSexo.ResumeLayout(false);
            this.grpBoxSexo.PerformLayout();
            this.grpBoxEstCiv.ResumeLayout(false);
            this.grpBoxEstCiv.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox grpBoxSexo;
        private System.Windows.Forms.RadioButton radioBtnFem;
        private System.Windows.Forms.RadioButton radioBntMasc;
        private System.Windows.Forms.GroupBox grpBoxEstCiv;
        private System.Windows.Forms.RadioButton radioBtnSolt;
        private System.Windows.Forms.RadioButton radioBtnCasado;
        private System.Windows.Forms.CheckedListBox checkedListBox;
        private System.Windows.Forms.Button btnMostrar;
        private System.Windows.Forms.Label lblHeader;
        private System.Windows.Forms.Label lblElemSelec;
    }
}