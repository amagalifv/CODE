using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsTP1
{
    public partial class FormEje2 : Form
    {
        public FormEje2()
        {
            InitializeComponent();
        }

        private void btnAgregar_Click(object sender, EventArgs e)
        {
            bool bandera = false;

            if (txtNombre.Text.Trim().Length==0 || txtApellido.Text.Trim().Length == 0)
            {
                if (txtNombre.Text.Trim().Length == 0)
                {
                    MessageBox.Show("Debe ingresar un nombre");
                }
                if (txtApellido.Text.Trim().Length == 0)
                {
                    MessageBox.Show("Debe ingresar un apellido");
                }
            }
            else
            {
                String aux2 = txtApellido.Text + ", " + txtNombre.Text;

                foreach (String aux in listBox.Items)
                {
                    if (aux2.ToUpper() == aux.ToUpper())
                    {
                        bandera = true;
                    }
                }
                if (bandera == true)
                {
                    MessageBox.Show("Debe ingresar un nombre y apellido que no exista ya en la lista");
                }
                else
                {
                    listBox.Items.Add(txtApellido.Text + ", " + txtNombre.Text);
                    //Para ordenar la listBox
                    listBox.Sorted = true;
                }
            }
            txtNombre.Text = "";
            txtApellido.Text = "";
        }

        private void btnBorrar_Click(object sender, EventArgs e)
        {
            if (listBox.SelectedItem == null)
            {
                MessageBox.Show("Debe Seleccionar un item de la lista para borrar");
            }
            else
            {
                listBox.Items.RemoveAt(listBox.SelectedIndex);
            }
        }
    }
}
