using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AppEscritorio1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnAceptar_Click(object sender, EventArgs e)
        { 
            MessageBox.Show("Bienvenido " + txtNombre.Text, "Atención");// ventana empergente de bienvenido
            
            lblMensaje.Text = "Bienvenido " + txtNombre.Text; //este muestra en el label en naranja
            
            txtNombre.Text = "";
        }
    }
}
