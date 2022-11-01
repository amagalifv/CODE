<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="ListadoSucursales.aspx.cs" Inherits="CapaVista.WebForm2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
    <head runat="server">
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
        <title></title>
        <style type="text/css">


            .auto-style1 {
                width: 100%;
            }
            .auto-style3 {
                width: 206px;
            }
            .auto-style2 {
                width: 358px;
            }
            </style>
    </head>

    <body>
        <form id="form2" runat="server">
            <div>
                <div>
                    <table class="auto-style1">
                        <tr>
                            <td>
                                <asp:HyperLink ID="hlAgregarSuc" runat="server" Font-Underline="True" ForeColor="Blue" NavigateUrl="~/AgregarSucursal.aspx">Agregar sucursal</asp:HyperLink>
                            </td>
                            <td>
                                <asp:HyperLink ID="hlListadoSuc" runat="server" Font-Underline="True" ForeColor="Blue" NavigateUrl="~/ListadoSucursales.aspx">Listado de sucursales</asp:HyperLink>
                            </td>
                            <td>
                                <asp:HyperLink ID="hlEliminarSuc" runat="server" Font-Underline="True" ForeColor="Blue" NavigateUrl="~/EliminarSucursales.aspx">Eliminar sucursal</asp:HyperLink>
                            </td>
                        </tr>
                    </table>
                </div>
            </div>
            <br />
            <br />
            <asp:Label ID="Label1" runat="server" Font-Bold="True" Font-Size="XX-Large" Text="Listado de Sucursales"></asp:Label>
            <br />
            <br />
            <br />
            <table class="auto-style1">
                <tr>
                    <td class="auto-style3">
                        <asp:Label ID="Label2" runat="server" Text="Ingrese ID Sucursal:"></asp:Label>
                    </td>
                    <td class="auto-style2">
                        <asp:TextBox ID="txtIdSucu" runat="server" Width="333px"></asp:TextBox>
                    </td>
                    <td>
                        <asp:Button ID="btnFiltrar" runat="server" Text="Filtrar" Width="121px" OnClick="btnFiltrar_Click" />
                        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                        <asp:Button ID="btnMostrarTodos" runat="server" Text="Mostrar Todos" OnClick="btnMostrarTodos_Click" />
                        &nbsp;<asp:CompareValidator ID="CompareValidator1" runat="server" ControlToValidate="txtIdSucu" ErrorMessage="*Debe ingresar un número entero" ForeColor="Red" Operator="GreaterThanEqual" Type="Integer" ValueToCompare="0"></asp:CompareValidator>
                    </td>
                </tr>
            </table>
            <asp:GridView ID="gwTabla" runat="server">
            </asp:GridView>
            <br />
        </form>
    </body>
</html>
