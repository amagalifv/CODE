using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CapaEntidades;

namespace CapaDao
{
    public class DaoSucursal
    {
        AccesoDB ds = new AccesoDB();
        public Sucursal getSucursal(Sucursal suc)
        {
            DataTable tabla = ds.ObtenerTabla("Sucursal", "Select * from Sucursal where Id_Sucursal = " + suc.getIdSucursal());
            suc.setIdSucursal(Convert.ToInt32(tabla.Rows[0][0].ToString()));
            suc.setNombre(tabla.Rows[0][1].ToString());
            suc.setDescripcion(tabla.Rows[0][2].ToString());
            return suc;
        }

        public Boolean existeSucursal(Sucursal suc)
        {
            String consulta = "Select * from Sucursal where NombreSucursal= '" + suc.getNombre() + "'";
            return ds.existe(consulta);
        }

        public DataTable getTablaSucursal()
        {
            DataTable tabla = ds.ObtenerTabla("Sucursal", "Select * from Sucursal");
            return tabla;
        }
        public DataTable getTablaSucursalJoin()
        {
            DataTable tabla = ds.ObtenerTabla("Sucursal", "SELECT Sucursal.Id_Sucursal, Sucursal.NombreSucursal, Sucursal.DescripcionSucursal, " +
                "Provincia.DescripcionProvincia as Provincia, Sucursal.DireccionSucursal FROM Sucursal INNER JOIN Provincia " +
                "ON Sucursal.Id_ProvinciaSucursal=Provincia.Id_Provincia;");
            return tabla;
        }

        public DataTable getTablaSucursalFiltrar(String id)
        {
            DataTable tabla = ds.ObtenerTabla("Sucursal", "SELECT Sucursal.Id_Sucursal, Sucursal.NombreSucursal, Sucursal.DescripcionSucursal, " +
                "Provincia.DescripcionProvincia as Provincia, Sucursal.DireccionSucursal FROM Sucursal INNER JOIN Provincia " +
                "ON Sucursal.Id_ProvinciaSucursal=Provincia.Id_Provincia WHERE Id_Sucursal= "+ id);
            return tabla;
        }

        public int eliminarSucursal(Sucursal sucu)
        {
            SqlCommand comando = new SqlCommand();
            ArmarParametrosSucursalEliminar(ref comando, sucu);
            return ds.EjecutarProcedimientoAlmacenado(comando, "spEliminarSucursal");
        }


        public int agregarSucursal(Sucursal sucu)
        {
            SqlCommand comando = new SqlCommand();
            ArmarParametrosSucursalAgregar(ref comando, sucu);
            return ds.EjecutarProcedimientoAlmacenado(comando, "spInsertarSucursal");
        }

        private void ArmarParametrosSucursalEliminar(ref SqlCommand Comando, Sucursal suc)
        {
            SqlParameter SqlParametros = new SqlParameter();
            SqlParametros = Comando.Parameters.Add("@IDSUCURSAL", SqlDbType.Int);
            SqlParametros.Value = suc.getIdSucursal();
        }

        private void ArmarParametrosSucursalAgregar(ref SqlCommand Comando, Sucursal sucu)
        {
            SqlParameter SqlParametros = new SqlParameter();
            SqlParametros = Comando.Parameters.Add("@NOMBRE", SqlDbType.VarChar);
            SqlParametros.Value = sucu.getNombre();
            SqlParametros = Comando.Parameters.Add("@DESCRIPCION", SqlDbType.VarChar);
            SqlParametros.Value = sucu.getDescripcion();
            SqlParametros = Comando.Parameters.Add("@IDPROVINCIA", SqlDbType.Int);
            SqlParametros.Value = sucu.getIdProvincia();
            SqlParametros = Comando.Parameters.Add("@DIRECCIONSUCURSAL", SqlDbType.VarChar);
            SqlParametros.Value = sucu.getDireccion();
        }
    }
}
