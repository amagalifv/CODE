using CapaDao;
using CapaEntidades;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CapaNegocio
{
    public class NegocioProvincia
    {
        public DataTable getTablaProvincia()
        {
            DaoProvincia dao = new DaoProvincia();
            return dao.getTablaProvincia();
        }
    }
}
