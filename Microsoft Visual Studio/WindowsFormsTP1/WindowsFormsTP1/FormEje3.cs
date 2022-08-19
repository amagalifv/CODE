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
    public partial class FormEje3 : Form
    {
        public FormEje3()
        {
            InitializeComponent();
        }

        private void btnMostrar_Click(object sender, EventArgs e)
        {
            lblHeader.Show();

            //Para Sexo
            lblElemSelec.Text = "• Sexo:";
            if (radioBtnFem.Checked)
            {
                lblElemSelec.Text+= " Femenino";
            }
            else
            {
                lblElemSelec.Text += " Masculino";
            }

            // Para Estado civil
            lblElemSelec.Text += "\n• Estado Civil:";
            if (radioBtnCasado.Checked)
            {
                lblElemSelec.Text += " Casado";
            }
            else
            {
                lblElemSelec.Text += " Soltero";
            }

            //Para oficios
            lblElemSelec.Text += "\n• Profesión:";
            bool bandera = true;
            
            foreach (String aux in checkedListBox.Items)
            {
                if (checkedListBox.GetItemChecked(checkedListBox.Items.IndexOf(aux)))
                {
                    lblElemSelec.Text += aux;
                    if (bandera == false)
                    {
                        lblElemSelec.Text += ", ";
                    }
                    bandera = false;
                    
                }
            }

            lblElemSelec.Show();
        }
    }
}
