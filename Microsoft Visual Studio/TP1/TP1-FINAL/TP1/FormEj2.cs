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
    public partial class FormEj2 : Form
    {
        public FormEj2()
        {
            InitializeComponent();
        }

        private void btnAgregar_Click(object sender, EventArgs e)
        {
            bool estado = false;
           
                if (txtNombre.Text.Trim() == "" || txtApellido.Text.Trim() == "")
                {
                    MessageBox.Show("DEBE INGRESAR UN NOMBRE Y UN APELLIDO");
                }
                else
                {
                    foreach (string aux in lbListaNombres.Items)
                    {
                        if (txtNombre.Text.Trim().ToUpper() + " " + txtApellido.Text.Trim().ToUpper() == aux.ToUpper())
                        {
                            MessageBox.Show("ESE NOMBRE YA FUE INGRESADO");
                            estado = true;
                        }
                    }
                    if (estado == false)
                    {
                        lbListaNombres.Items.Add(txtNombre.Text.Trim() + " " + txtApellido.Text.Trim());
                    }
                }
                txtNombre.Text = "";
                txtApellido.Text = "";
        }

        private void btnBorrar_Click(object sender, EventArgs e)
        {
            if(lbListaNombres.SelectedIndex==-1)
            {
                MessageBox.Show("DEBE SELECCIONAR UN ELEMENTO O LA LISTA ESTA VACIA");
            }
            else
            { 
                lbListaNombres.Items.RemoveAt(lbListaNombres.SelectedIndex);
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
