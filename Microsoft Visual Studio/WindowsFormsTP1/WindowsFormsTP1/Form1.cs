using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsTP1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            //// Cuando se apreta bntEje2
            FormEje2 formEjercicio2 = new FormEje2();
            formEjercicio2.ShowDialog();

        }

        private void button1_Click(object sender, EventArgs e)
        {
            // Cuando se apreta bntEje1
            
            FormEje1 formEjercicio1 = new FormEje1();
            formEjercicio1.ShowDialog();
            
        }

        private void btnEje3_Click(object sender, EventArgs e)
        {
            // Cuando se apreta bntEje3
            FormEje3 formEjercicio3 = new FormEje3();
            formEjercicio3.ShowDialog();
            
        }
    }
}
