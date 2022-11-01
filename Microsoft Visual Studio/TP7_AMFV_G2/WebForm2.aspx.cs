using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP7_AMFV_G2
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["Tabla"] != null)
            {
                gw_SucSeleccionadas.DataSource = (DataTable)Session["Tabla"];
                gw_SucSeleccionadas.DataBind();
            }
        }
    }
}