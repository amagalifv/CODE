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
    public partial class FormEje1 : Form
    {
        public FormEje1()
        {
            InitializeComponent();
        }


        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void btnAgregar_Click(object sender, EventArgs e)
        {
            bool bandera=false;

            if (txtAgregar.Text.Trim().Length == 0)
            {
                MessageBox.Show("Debe Ingresar un nombre");
            } 
            else
            {
                
                foreach(String aux in ListBoxPrincipio.Items)                
                {
                    if (txtAgregar.Text.ToUpper()== aux.ToUpper())
                    {
                        bandera=true;
                    }
                }
                if (bandera == true)
                {
                    MessageBox.Show("Debe ingresar un nombre que no exista ya en la lista");
                }
                else
                {
                    ListBoxPrincipio.Items.Add(txtAgregar.Text);
                }
            }
            txtAgregar.Text = "";
        }

        private void btnPasarUno_Click(object sender, EventArgs e)
        {
            bool bandera = false;

            if (ListBoxPrincipio.SelectedItem == null)
            {
                MessageBox.Show("Debe Seleccionar un item de la primer lista, si no hay primero agregue uno!");
                return;
                // Con el return prevengo que se produzca una excepcion
            }
            else
            {
                foreach (String aux in ListBoxFinal.Items)
                {
                    if (ListBoxPrincipio.SelectedItem.ToString().ToUpper() == aux.ToUpper())
                    {
                        bandera = true;
                    }
                }
                if (bandera == true)
                {
                    MessageBox.Show("No puede agregar ese nombre a la segunda lista ya que existe previamente en ella");
                }
                else
                {
                    ListBoxFinal.Items.Add(ListBoxPrincipio.SelectedItem.ToString());
                    ListBoxPrincipio.Items.RemoveAt(ListBoxPrincipio.SelectedIndex);
                }

            }
            
        }

        private void btnPasarTodos_Click(object sender, EventArgs e)
        {
            if (ListBoxPrincipio.Items.Count == 0)
            {
                MessageBox.Show("No hay items en la primer lista para agragar");
                return;
                // Con el return prevengo que se produzca una excepcion
            }
            else
            {

                foreach (String aux in ListBoxPrincipio.Items)
                {
                    ListBoxFinal.Items.Add(aux);
                }
                ListBoxPrincipio.Items.Clear();
                
            }
            
        }
    }
}
