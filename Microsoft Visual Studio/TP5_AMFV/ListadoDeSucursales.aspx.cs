using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP5_AMFV
{
    public partial class ListadoDeSucursales : System.Web.UI.Page
    {
        String miQuery = "SELECT S.Id_Sucursal, S.NombreSucursal, S.DescripcionSucursal, P.DescripcionProvincia, S.DireccionSucursal FROM Sucursal S " +
            "INNER JOIN Provincia P ON S.Id_ProvinciaSucursal = P.Id_Provincia;";
        protected void Page_Load(object sender, EventArgs e)
        {
            if (IsPostBack == false)
            {
                DBConexion obj = new DBConexion();

                obj.cargarGridView(miQuery, gwTabla);
            }
        }

        protected void btnFiltrar_Click(object sender, EventArgs e)
        {
            miQuery = "SELECT S.Id_Sucursal, S.NombreSucursal, S.DescripcionSucursal, P.DescripcionProvincia, S.DireccionSucursal FROM Sucursal S " +
                "INNER JOIN Provincia P ON S.Id_ProvinciaSucursal = P.Id_Provincia WHERE S.Id_Sucursal = "+ txtIdSucu.Text.Trim().ToString()+";";

            DBConexion obj = new DBConexion();

            obj.cargarGridView(miQuery, gwTabla);

            txtIdSucu.Text = "";
        }

        protected void btnMostrarTodos_Click(object sender, EventArgs e)
        {
            miQuery = "SELECT S.Id_Sucursal, S.NombreSucursal, S.DescripcionSucursal, P.DescripcionProvincia, S.DireccionSucursal FROM Sucursal S " +
                "INNER JOIN Provincia P ON S.Id_ProvinciaSucursal = P.Id_Provincia;";

            DBConexion obj = new DBConexion();

            obj.cargarGridView(miQuery, gwTabla);
        }
    }
}