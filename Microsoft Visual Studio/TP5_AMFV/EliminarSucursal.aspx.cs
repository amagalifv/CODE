using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP5_AMFV
{
    public partial class EliminarSucursal : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnAceptar_Click(object sender, EventArgs e)
        {
            int filasAfectadas;


            if (txtIdSucursal.Text.Trim().Length != 0)
            {
                DBConexion obj = new DBConexion();


                filasAfectadas = obj.ModificarDB("DELETE FROM Sucursal WHERE Id_Sucursal = " + txtIdSucursal.Text.Trim().ToString() + ";");

                if (filasAfectadas == 0)
                {
                    lblResulEliminar.ForeColor = System.Drawing.Color.Red;
                    lblResulEliminar.Text = "Error de eliminado, el ID no existe";
                }
                else
                {
                    lblResulEliminar.ForeColor = System.Drawing.Color.Green;
                    lblResulEliminar.Text = "La sucursal se ha eliminado con éxito";
                }

            }

            txtIdSucursal.Text = "";
        }
    }
}