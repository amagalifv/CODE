using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CapaDao
{
    public class DaoProvincia
    {

        AccesoDB ds = new AccesoDB();
        public DataTable getTablaProvincia()
        {
            DataTable tabla = ds.ObtenerTabla("Provincia", "Select Id_Provincia, DescripcionProvincia from Provincia");
            return tabla;
        }
    }
}
