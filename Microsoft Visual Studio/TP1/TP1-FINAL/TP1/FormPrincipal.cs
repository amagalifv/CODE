using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TP1
{
   
    public partial class FormPrincipal : Form
    {
        public FormPrincipal()
        {
            InitializeComponent();
        }

        private void btnEjercicio1_Click(object sender, EventArgs e)
        {
            
            FormEj1 ej1 = new FormEj1();
            this.Hide();
            

            ej1.Show();
            
        }

        private void btnEjercicio2_Click(object sender, EventArgs e)
        {
            FormEj2 ej2 = new FormEj2();
            this.Hide();

            ej2.Show();

        }

        private void btnEjercicio3_Click(object sender, EventArgs e)
        {
            FormEj3 ej3 = new FormEj3();
            this.Hide();

            ej3.Show();
        }

        private void btnCerrar_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
