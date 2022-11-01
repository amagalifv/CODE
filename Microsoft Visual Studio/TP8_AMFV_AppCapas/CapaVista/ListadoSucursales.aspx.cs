using CapaNegocio;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace CapaVista
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if(!IsPostBack)
            {
                NegocioSucursal ns = new NegocioSucursal();

                gwTabla.DataSource = ns.getTablaSucursalJoin();
                gwTabla.DataBind();
            }
        }

        protected void btnMostrarTodos_Click(object sender, EventArgs e)
        {
            NegocioSucursal ns = new NegocioSucursal();

            txtIdSucu.Text = "";

            gwTabla.DataSource = ns.getTablaSucursalJoin();
            gwTabla.DataBind();
        }

        protected void btnFiltrar_Click(object sender, EventArgs e)
        {
            NegocioSucursal ns = new NegocioSucursal();

            txtIdSucu.Text = "";

            gwTabla.DataSource = ns.getTablaSucursalFiltrar(txtIdSucu.Text.ToString());
            gwTabla.DataBind();
        }
    }
}