﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP2
{
    public partial class WebForm4_Valido : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            String usuario;

            usuario = Request.QueryString["usu"];
            lblValido.Text += usuario;
        }
    }
}