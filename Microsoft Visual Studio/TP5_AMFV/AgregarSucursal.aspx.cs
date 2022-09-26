using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;

namespace TP5_AMFV
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (IsPostBack == false)
            {
                DBConexion obj = new DBConexion();

                obj.cargarDDL(ddlProvincia, "Provincia", "DescripcionProvincia", "Id_Provincia");

            }
        }

        protected void btnAceptar_Click(object sender, EventArgs e)
        {
            DBConexion obj = new DBConexion();


            int filasAfectadas = obj.ModificarDB("INSERT INTO Sucursal (NombreSucursal, DescripcionSucursal, Id_ProvinciaSucursal, DireccionSucursal) " +
                "VALUES ('" + txtNomSuc.Text.Trim().ToString() + 
                "', '" + txtDescripcion.Text.Trim().ToString() +
                "', '" + ddlProvincia.SelectedValue.ToString() + 
                "', '" + txtDireccion.Text.Trim().ToString() + "');");


            if (filasAfectadas==0)
            {
                lblResultAceptar.ForeColor = System.Drawing.Color.Red;
                lblResultAceptar.Text = "Error de guardado en DB";
            }
            else
            {
                lblResultAceptar.ForeColor = System.Drawing.Color.Green;
                lblResultAceptar.Text = "La sucursal se ha agregado con éxito";
                limpiarText();
            }

        }

        public void limpiarText()
        {
            txtNomSuc.Text = "";
            txtDescripcion.Text = "";
            txtDireccion.Text = "";
        }
    }
}