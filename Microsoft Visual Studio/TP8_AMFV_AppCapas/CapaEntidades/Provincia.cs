using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CapaEntidades
{
    public class Provincia
    {
        private int idProv;
        private string prov;

        public Provincia()
        { }
        public int getIdProvincia()
        {
            return idProv;
        }
        public void setIdProvincia(int idProvincia)
        {
            this.idProv = idProvincia;
        }
        public String getNombreProv()
        {
            return prov;
        }
        public void setNombreProv(String nombre)
        {
            prov = nombre;
        }
    }
}
