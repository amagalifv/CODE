using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP2
{
    public partial class FormPrincipal : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnGenerarTabla_Click(object sender, EventArgs e)
        {
            bool estado = true;

            if((txtNombre1.Text.Trim()=="") || (txtNombre2.Text.Trim()==""))
            {
                estado = false;
            }
            if((txtCantidad1.Text.Trim()=="") || (txtCantidad1.Text.Trim()==""))
            {
                estado = false;
            }

            if(estado==true)
            {
                int cant1 = int.Parse(txtCantidad1.Text);
                int cant2 = int.Parse(txtCantidad2.Text);

                if(cant1>=0 && cant2>=0)
                {
                    string tabla = "<table border='1'>";

                    tabla += "<tr> <td><b>Producto</b></td> <td><b>Cantidad</b></td> </tr>" +
                             "<tr> <td>" + txtNombre1.Text + "</td><td>" + cant1 + "</td></tr>" +
                             "<tr> <td>" + txtNombre2.Text + "</td><td>" + cant2 + "</td></tr>" +
                             "<tr> <td> TOTAL: </td><td>" + (cant1 + cant2) + "</td> </tr> </tabla>";

                    lblTabla.Text = tabla;
                }   
                else
                {
                    lblTabla.Text = "La cantida de productos debe ser mayor o igual a 0";
                }
            }
            else
            {
                lblTabla.Text = "Ingrese productos y/o cantidades validas";
            }
            
            txtCantidad1.Text = "";
            txtCantidad2.Text = "";
            txtNombre1.Text = "";
            txtNombre2.Text = "";
        } 
    }
}