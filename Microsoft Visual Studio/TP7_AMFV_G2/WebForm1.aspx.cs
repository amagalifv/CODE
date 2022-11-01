using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP7_AMFV_G2
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                cargarDataList();
            }
        }

        public void cargarDataList()
        {
            Conexion DBcon = new Conexion();
            DataSet dSet = DBcon.cargarDatosEnDataSet("SELECT [DescripcionProvincia], [Id_Provincia] FROM [Provincia]", "Provincias");
            datListProv.DataSource = dSet.Tables["Provincias"];
            datListProv.DataBind();
        }

        protected void btnProvincia_Command(object sender, CommandEventArgs e)
        {
            if (e.CommandName == "eventoSeleccionar")
            {
                SqlDataSource2.SelectCommand = "SELECT [Id_Sucursal], [NombreSucursal], [DescripcionSucursal], [Id_HorarioSucursal], [Id_ProvinciaSucursal], " +
                    "[DireccionSucursal], [URL_Imagen_Sucursal] FROM [Sucursal] WHERE [Id_ProvinciaSucursal] = " + e.CommandArgument.ToString();
                SqlDataSource2.DataBind();
                listW_Sucursales.DataBind();
            }
        }

        protected void btnBuscar_Click(object sender, EventArgs e)
        {
            if (txtBuscar.Text.Trim().Length !=0 )
            {
                SqlDataSource2.SelectCommand = "SELECT [Id_Sucursal], [NombreSucursal], [DescripcionSucursal], [Id_HorarioSucursal], [Id_ProvinciaSucursal], " +
                    "[DireccionSucursal], [URL_Imagen_Sucursal] FROM [Sucursal] WHERE [NombreSucursal] = '" + txtBuscar.Text.Trim() + "';";
                SqlDataSource2.DataBind();
                listW_Sucursales.DataBind();
            }
            else
            {
                SqlDataSource2.SelectCommand = "SELECT [Id_Sucursal], [NombreSucursal], [DescripcionSucursal], [Id_HorarioSucursal], [Id_ProvinciaSucursal], " +
                    "[DireccionSucursal], [URL_Imagen_Sucursal] FROM [Sucursal]";
                SqlDataSource2.DataBind();
                listW_Sucursales.DataBind();
            }
        }

        protected void btnSeleccionar_Command(object sender, CommandEventArgs e)
        {
            String datosRuteados = "";
            
            if (e.CommandName == "eventoSeleccionar")
            {
                datosRuteados=e.CommandArgument.ToString();
            }

            Conexion DBcon = new Conexion();
            DataSet dSet = DBcon.cargarDatosEnDataSet("SELECT [Id_Sucursal], [NombreSucursal], [DescripcionSucursal] FROM [Sucursal] " +
                "WHERE [Id_Sucursal] = " + datosRuteados, "Seleccionados");

            cargarVarSession(dSet, "Seleccionados");
        }



        public DataTable crearTabla()
        {
            DataTable dt = new DataTable();
            DataColumn col = new DataColumn("Id_Sucursal", System.Type.GetType("System.String"));
            dt.Columns.Add(col);

            col = new DataColumn("NombreSucursal", System.Type.GetType("System.String"));
            dt.Columns.Add(col);

            col = new DataColumn("DescripcionSucursal", System.Type.GetType("System.String"));
            dt.Columns.Add(col);

            return dt;
        }

        public void agregarFila(DataTable tabla, String idSuc, String nomSuc, String DescSuc)
        {
            DataRow dr = tabla.NewRow();
            dr["Id_Sucursal"] = idSuc;
            dr["NombreSucursal"] = nomSuc;
            dr["DescripcionSucursal"] = DescSuc;
            tabla.Rows.Add(dr);
        }

        protected void btnSeleccionar2_Command(object sender, CommandEventArgs e)
        {
            String datosRuteados = "";

            if (e.CommandName == "eventoSeleccionar2")
            {
                datosRuteados = e.CommandArgument.ToString();
            }

            Conexion DBcon = new Conexion();
            DataSet dSet = DBcon.cargarDatosEnDataSet("SELECT [Id_Sucursal], [NombreSucursal], [DescripcionSucursal] FROM [Sucursal] " +
                "WHERE [Id_Sucursal] = " + datosRuteados, "Selecciona2");

            cargarVarSession(dSet, "Selecciona2");
        }

        public void cargarVarSession(DataSet dSet, String nombreTabla)
        {
            String idSuc = "";
            String nomSuc = "";
            String descSuc = "";

            foreach (DataRow row in dSet.Tables[nombreTabla].Rows)
            {
                idSuc = row["Id_Sucursal"].ToString();
                nomSuc = row["NombreSucursal"].ToString();
                descSuc = row["DescripcionSucursal"].ToString();
            }


            if (Session["Tabla"] == null)
            {
                Session["Tabla"] = crearTabla();
            }

            agregarFila((DataTable)Session["Tabla"], idSuc, nomSuc, descSuc);
        }
    }
}