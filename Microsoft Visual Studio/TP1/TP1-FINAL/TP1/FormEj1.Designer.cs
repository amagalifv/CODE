
namespace TP1
{
    partial class FormEj1
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
            this.lblNombre = new System.Windows.Forms.Label();
            this.txtNombres = new System.Windows.Forms.TextBox();
            this.btnAgregar = new System.Windows.Forms.Button();
            this.lbNombresIngreso = new System.Windows.Forms.ListBox();
            this.lbNombresEgreso = new System.Windows.Forms.ListBox();
            this.btnPasarSeleccion = new System.Windows.Forms.Button();
            this.btnPasarTodos = new System.Windows.Forms.Button();
            this.btnMenuPrincipal = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lblNombre
            // 
            this.lblNombre.AutoSize = true;
            this.lblNombre.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblNombre.Location = new System.Drawing.Point(121, 77);
            this.lblNombre.Name = "lblNombre";
            this.lblNombre.Size = new System.Drawing.Size(153, 18);
            this.lblNombre.TabIndex = 4;
            this.lblNombre.Text = "Ingrese su nombre:";
            // 
            // txtNombres
            // 
            this.txtNombres.Location = new System.Drawing.Point(280, 78);
            this.txtNombres.Name = "txtNombres";
            this.txtNombres.Size = new System.Drawing.Size(232, 20);
            this.txtNombres.TabIndex = 5;
            // 
            // btnAgregar
            // 
            this.btnAgregar.Location = new System.Drawing.Point(533, 75);
            this.btnAgregar.Name = "btnAgregar";
            this.btnAgregar.Size = new System.Drawing.Size(105, 23);
            this.btnAgregar.TabIndex = 6;
            this.btnAgregar.Text = "Agregar";
            this.btnAgregar.UseVisualStyleBackColor = true;
            this.btnAgregar.Click += new System.EventHandler(this.btnAgregar_Click);
            // 
            // lbNombresIngreso
            // 
            this.lbNombresIngreso.FormattingEnabled = true;
            this.lbNombresIngreso.Location = new System.Drawing.Point(124, 143);
            this.lbNombresIngreso.Name = "lbNombresIngreso";
            this.lbNombresIngreso.Size = new System.Drawing.Size(120, 134);
            this.lbNombresIngreso.TabIndex = 7;
            // 
            // lbNombresEgreso
            // 
            this.lbNombresEgreso.FormattingEnabled = true;
            this.lbNombresEgreso.Location = new System.Drawing.Point(518, 143);
            this.lbNombresEgreso.Name = "lbNombresEgreso";
            this.lbNombresEgreso.Size = new System.Drawing.Size(120, 134);
            this.lbNombresEgreso.TabIndex = 7;
            // 
            // btnPasarSeleccion
            // 
            this.btnPasarSeleccion.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnPasarSeleccion.Location = new System.Drawing.Point(350, 143);
            this.btnPasarSeleccion.Name = "btnPasarSeleccion";
            this.btnPasarSeleccion.Size = new System.Drawing.Size(75, 42);
            this.btnPasarSeleccion.TabIndex = 6;
            this.btnPasarSeleccion.Text = ">";
            this.btnPasarSeleccion.UseVisualStyleBackColor = true;
            this.btnPasarSeleccion.Click += new System.EventHandler(this.btnPasarSeleccion_Click);
            // 
            // btnPasarTodos
            // 
            this.btnPasarTodos.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnPasarTodos.Location = new System.Drawing.Point(350, 235);
            this.btnPasarTodos.Name = "btnPasarTodos";
            this.btnPasarTodos.Size = new System.Drawing.Size(75, 42);
            this.btnPasarTodos.TabIndex = 6;
            this.btnPasarTodos.Text = ">>";
            this.btnPasarTodos.UseVisualStyleBackColor = true;
            this.btnPasarTodos.Click += new System.EventHandler(this.btnPasarTodos_Click);
            // 
            // btnMenuPrincipal
            // 
            this.btnMenuPrincipal.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnMenuPrincipal.Location = new System.Drawing.Point(280, 345);
            this.btnMenuPrincipal.Name = "btnMenuPrincipal";
            this.btnMenuPrincipal.Size = new System.Drawing.Size(232, 55);
            this.btnMenuPrincipal.TabIndex = 8;
            this.btnMenuPrincipal.Text = "Menu Principal";
            this.btnMenuPrincipal.UseVisualStyleBackColor = true;
            this.btnMenuPrincipal.Click += new System.EventHandler(this.btnMenuPrincipal_Click);
            // 
            // FormEj1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnMenuPrincipal);
            this.Controls.Add(this.lbNombresEgreso);
            this.Controls.Add(this.lbNombresIngreso);
            this.Controls.Add(this.btnPasarTodos);
            this.Controls.Add(this.btnPasarSeleccion);
            this.Controls.Add(this.btnAgregar);
            this.Controls.Add(this.txtNombres);
            this.Controls.Add(this.lblNombre);
            this.Name = "FormEj1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "FormEj1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblNombre;
        private System.Windows.Forms.TextBox txtNombres;
        private System.Windows.Forms.Button btnAgregar;
        private System.Windows.Forms.ListBox lbNombresIngreso;
        private System.Windows.Forms.ListBox lbNombresEgreso;
        private System.Windows.Forms.Button btnPasarSeleccion;
        private System.Windows.Forms.Button btnPasarTodos;
        private System.Windows.Forms.Button btnMenuPrincipal;
    }
}