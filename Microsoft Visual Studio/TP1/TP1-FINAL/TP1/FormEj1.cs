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
    public partial class FormEj1 : Form
    {
        public FormEj1()
        {
            InitializeComponent();
        }

        private void btnAgregar_Click(object sender, EventArgs e)
        {
            bool estado = true;
            if (txtNombres.Text.Trim() != "")
            {
                foreach (string aux in lbNombresIngreso.Items)
                {
                    if (txtNombres.Text.Trim().ToUpper() == aux.Trim().ToUpper())
                    {
                        estado = false;
                    }
                }
                foreach (string aux in lbNombresEgreso.Items)
                {
                    if (txtNombres.Text.Trim().ToUpper() == aux.Trim().ToUpper())
                    {
                        estado = false;
                    }
                }
                if (estado == true)
                {
                    lbNombresIngreso.Items.Add(txtNombres.Text.Trim());
                }
                else
                {
                    MessageBox.Show("EL NOMBRE QUE QUIERE INGRESAR YA EXISTE");
                }
            }
            else
            {
                MessageBox.Show("DEBE INGRESAR UN NOMBRE");
            }
            txtNombres.Text = "";
        }


        private void btnPasarSeleccion_Click(object sender, EventArgs e)
        {
            if (lbNombresIngreso.SelectedIndex == -1)
            {
                MessageBox.Show("DEBE SELECCIONAR UN NOMBRE");
            }
            else
            {
                lbNombresEgreso.Items.Add(lbNombresIngreso.SelectedItem);
                lbNombresIngreso.Items.RemoveAt(lbNombresIngreso.SelectedIndex);
            }
        }

        private void btnPasarTodos_Click(object sender, EventArgs e)
        {
            if(lbNombresIngreso.Items.Count==0)
            {
                MessageBox.Show("LA LISTA ESTA VACIA");
            }
            else
            {
                foreach (object aux in lbNombresIngreso.Items)
                {
                    lbNombresEgreso.Items.Add(aux);
                }
                lbNombresIngreso.Items.Clear();
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
