using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using CapaNegocio;
using CapaEntidades;
using System.Data;

namespace CapaVista
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                NegocioProvincia np = new NegocioProvincia();
                DataTable tabla1 = np.getTablaProvincia();

                ddlProvincia.DataSource = tabla1;
                ddlProvincia.DataTextField="DescripcionProvincia";
                ddlProvincia.DataValueField = "Id_Provincia";
                ddlProvincia.DataBind();
            }
        }

        protected void btnAceptar_Click(object sender, EventArgs e)
        {
            Boolean resultado;
            NegocioSucursal ns = new NegocioSucursal();

            Sucursal suc = new Sucursal(txtNomSuc.Text, txtDescripcion.Text, Convert.ToInt32(ddlProvincia.SelectedValue.ToString()),txtDireccion.Text);

            resultado=ns.agregarSucursal(suc);

            if (resultado)
            {
                lblResultAceptar.Text = "Se agregó la sucursal con éxito";
                lblResultAceptar.ForeColor = System.Drawing.Color.Green;
                limpiarAgregar();
            }
            else
            {
                lblResultAceptar.Text = "No se pudo agregas la sucursal";
                lblResultAceptar.ForeColor = System.Drawing.Color.Red;
            }

        }

        public void limpiarAgregar()
        {
            txtNomSuc.Text = "";
            txtDescripcion.Text = "";
            txtDireccion.Text = "";
        }
    }
}