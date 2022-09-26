using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Services.Description;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP2
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnGenTabla_Click(object sender, EventArgs e)
        {
            if (txtProd1.Text.Trim().Length==0 || txtProd2.Text.Trim().Length == 0 || txtCantProd2.Text.Trim().Length==0 || txtCantProd1.Text.Trim().Length == 0) 
            {
                //myLabel.ForeColor = System.Drawing.Color.Red
                lblTabla.ForeColor = System.Drawing.Color.Red;
                lblTabla.Text = "Debe llenar todos los campos!";
                return;
            }
            else
            {
                lblTabla.ForeColor = System.Drawing.Color.Black;
                int cant1 = int.Parse(txtCantProd1.Text);
                int cant2 = int.Parse(txtCantProd2.Text);
                String tabla = "<table border='1'>";

                tabla += "<tr> <td>Producto</td> <td>Cantidad</td> </tr>";
                tabla += "<tr> <td>" + txtProd1.Text + "</td> <td>" + txtCantProd1.Text + "</td> </tr>";
                tabla += "<tr> <td>" + txtProd2.Text + "</td> <td>" + txtCantProd2.Text + "</td> </tr>";
                tabla += "<tr> <td>Total</td> <td>" + (cant1 + cant2) + "</td> </tr>";

                lblTabla.Text = tabla;
                txtProd1.Text = "";
                txtProd2.Text = "";
                txtCantProd1.Text = "";
                txtCantProd2.Text = "";
            }
        }
    }
}