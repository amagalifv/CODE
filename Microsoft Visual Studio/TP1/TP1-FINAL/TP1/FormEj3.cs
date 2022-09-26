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
    public partial class FormEj3 : Form
    {
        public FormEj3()
        {
            InitializeComponent();
        }

        string Sexo = "Femenino";
        string Estado = "Casado";

        private void btnFemenino_CheckedChanged(object sender, EventArgs e)
        {
            Sexo = "Femenino";
        }

        private void btnMasculino_CheckedChanged(object sender, EventArgs e)
        {
            Sexo = "Masculino";
        }

        private void btnCasado_CheckedChanged(object sender, EventArgs e)
        {
            Estado = "Casado";
        }

        private void btnSoltero_CheckedChanged(object sender, EventArgs e)
        {
            Estado = "Soltero";
        }

        private void btnMostrar_Click(object sender, EventArgs e)
        {
            if(chlbOficios.CheckedItems.Count==0)
            {
                MessageBox.Show("DEBE SELECCIONAR AL MENOS UN OFICIO");
            }
            else
            {
                lbElementosSeleccionados.Visible = true;
                lbElementosSeleccionados.Text = "Usted selecciono los siguientes elementos: \n\n" + "Sexo: " + Sexo + "\nEstado Civil: " + Estado + "\nOficio: \n";
                foreach(string aux in chlbOficios.CheckedItems)
                {
                    lbElementosSeleccionados.Text += " - " + aux + "\n";
                }
            }
        }

        private void btnMenuPrincipal_Click(object sender, EventArgs e)
        {
            FormPrincipal menu = new FormPrincipal();
            this.Close();
            menu.Show();
        }  
    }
}
