using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP2
{
    public partial class Ejercicio2_2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            string Nombre;
            string Apellido;
            string Zona;
            CheckBoxList Temas;

            Nombre = Request["txtNombre"].ToString();
            Apellido = Request["txtApellido"].ToString();
            Zona = Request["ddlCiudad"].ToString();

            Temas = ((CheckBoxList)PreviousPage.FindControl("clbTemas"));

            lblResumen.Text += "Nombre: <b>" + Nombre + "</b> <br/>";
            lblResumen.Text += "Apellido: <b>" + Apellido + "</b> <br/>";
            lblResumen.Text += "Zona: <b>" + Zona + "</b> <br/>";

            lblResumen.Text += "Los temas elegidos son: <br/>";
            foreach(ListItem item in Temas.Items)
            {
                if (item.Selected == true)
                {
                    lblResumen.Text += "<b>" + item + "</b> <br/>";
                }
            }
        }
    }
}