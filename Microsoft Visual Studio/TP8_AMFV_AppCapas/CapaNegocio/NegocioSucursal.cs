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
    public class NegocioSucursal
    {
        public DataTable getTablaSucursal()
        {
            DaoSucursal dao = new DaoSucursal();
            return dao.getTablaSucursal();
        }

        public DataTable getTablaSucursalJoin()
        {
            DaoSucursal dao = new DaoSucursal();
            return dao.getTablaSucursalJoin();
        }

        public DataTable getTablaSucursalFiltrar(String id)
        {
            DaoSucursal dao = new DaoSucursal();
            return dao.getTablaSucursalFiltrar(id);
        }

        public Sucursal getUnaSucursal(int id)
        {
            DaoSucursal dao = new DaoSucursal();
            Sucursal sucu = new Sucursal();
            sucu.setIdSucursal(id);
            return dao.getSucursal(sucu);
        }

        public bool eliminarSucursal(int id)
        {  
            DaoSucursal dao = new DaoSucursal();
            Sucursal sucu = new Sucursal();
            sucu.setIdSucursal(id);

            //Validar id existente 
            if (dao.existeSucursal(sucu))
            {
                return false;
            }

            int op = dao.eliminarSucursal(sucu);
            if (op == 1)
                return true;
            else
                return false;
        }

        public bool agregarSucursal(Sucursal sucursalRecibida)
        {
            int cantFilas = 0;

            DaoSucursal dao = new DaoSucursal();
            if (dao.existeSucursal(sucursalRecibida) == false)
            {
                cantFilas = dao.agregarSucursal(sucursalRecibida);
            }

            if (cantFilas == 1)
                return true;
            else
                return false;
        }
    }
}
