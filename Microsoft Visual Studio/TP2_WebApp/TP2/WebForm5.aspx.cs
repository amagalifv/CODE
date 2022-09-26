using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP2
{
    public partial class WebForm5 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnCalcPrecio_Click(object sender, EventArgs e)
        {
            lblPrecioFinal.Text = "";
            float precio=0.0f;
            int i;
            int j = 0;

            i =ddlMemoria.SelectedIndex;

            switch (i)
            {
                case 0: 
                    precio += 200.0f;
                    break;
                case 1:
                    precio += 375.0f;
                    break;
                case 2:
                    precio += 500.0f;
                    break;
                default:
                    break;

            }

            foreach (ListItem aux in cblAccesorios.Items)
            {
                
                if (aux.Selected==true)
                {
                    switch (j)
                    {
                        case 0:
                            precio += 2000.5f;
                            break;
                        case 1:
                            precio += 550.5f;
                            break;
                        case 2:
                            precio += 1200.0f;
                            break;
                        default:
                            break;

                    }
                }
                j++;
            }

            lblPrecioFinal.Text += "El precio final es: $" + precio.ToString();
            
        }
    }
}