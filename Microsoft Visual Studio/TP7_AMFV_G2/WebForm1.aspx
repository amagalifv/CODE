<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="TP7_AMFV_G2.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
        .auto-style2 {
            width: 365px;
            height: 23px;
        }
        .auto-style3 {
            width: 385px;
            height: 23px;
        }
        .auto-style7 {
            width: 312px;
            height: 23px;
        }
        .auto-style9 {
            width: 787px;
        }
        .auto-style10 {
            width: 486px;
        }
        .auto-style11 {
            width: 165px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <table class="auto-style1">
                <tr>
                    <td class="auto-style2">
                        <asp:Label ID="lblGrupo" runat="server" Text="Grupo N°2:" Font-Bold="True"></asp:Label>
                    </td>
                    <td class="auto-style3">
                        <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/WebForm1.aspx">Listado de Sucursales</asp:HyperLink>
                    </td>
                    <td class="auto-style7">
                        <asp:HyperLink ID="HyperLink2" runat="server" NavigateUrl="~/WebForm2.aspx">Mostrar Sucursales Seleccionadas</asp:HyperLink>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style2">
                        <asp:Label ID="Label3" runat="server" Text="•Juan Manuel Galarce &lt;/br&gt; •Ana Magalí Fernández Vilchez &lt;/br&gt; •Melanie Del Rosario Degregorio Marrero &lt;/br&gt; •Melina Carraro &lt;/br&gt; •Nicolás Gabriel Beati"></asp:Label>
                    </td>
                    <td class="auto-style3">
                        <asp:Label ID="Label1" runat="server" Font-Bold="True" Font-Size="X-Large" Text="Listado de Sucursales"></asp:Label>
                    </td>
                    <td class="auto-style7">&nbsp;</td>
                </tr>
                <tr>
                    <td class="auto-style2">
                        &nbsp;</td>
                    <td class="auto-style3">
                        <asp:Label ID="Label2" runat="server" Text="Búsqueda nombre de sucursal:"></asp:Label>
                        &nbsp;<asp:TextBox ID="txtBuscar" runat="server" Width="127px"></asp:TextBox>
                        <asp:Button ID="btnBuscar" runat="server" Text="Buscar" OnClick="btnBuscar_Click" />
                    </td>
                    <td class="auto-style7">&nbsp;</td>
                </tr>
            </table>
            <br />
            <br />
            <table class="auto-style1">
                <tr>
                    <td class="auto-style10">
                        <asp:DataList ID="datListProv" runat="server" DataKeyField="Id_Provincia">
                            <ItemTemplate>
                                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                                <asp:Button ID="btnProvincia" runat="server" Text='<%# Eval("DescripcionProvincia") %>' Width="200px" CommandArgument='<%# Eval("Id_Provincia") %>' CommandName="eventoSeleccionar" OnCommand="btnProvincia_Command" />
<br />
                            </ItemTemplate>
                        </asp:DataList>
                    </td>
                    <td class="auto-style9">
                        <asp:ListView ID="listW_Sucursales" runat="server" GroupItemCount="3" DataSourceID="SqlDataSource2">
                            <AlternatingItemTemplate>
                                <td runat="server" style="background-color: #FFFFFF;color: #284775; text-align: center;" class="auto-style11">&nbsp;<asp:Label ID="NombreSucursalLabel" runat="server" Font-Bold="True" Text='<%# Eval("NombreSucursal") %>'></asp:Label>
                                    <br />
                                    <asp:ImageButton ID="ImageButton1" runat="server" ImageUrl='<%# Eval("URL_Imagen_Sucursal") %>' Width="100px" />
                                    <br />
                                    <asp:Label ID="DescripcionSucursalLabel" runat="server" Text='<%# Eval("DescripcionSucursal") %>'></asp:Label>
                                    <br />
                                    <asp:Button ID="btnSeleccionar2" runat="server" Text="Seleccionar" CommandArgument='<%# Bind("Id_Sucursal") %>' CommandName="eventoSeleccionar2" OnCommand="btnSeleccionar2_Command" />
                                </td>
                            </AlternatingItemTemplate>
                            <EditItemTemplate>
                                <td runat="server" style="background-color: #999999;">Id_Sucursal:
                                    <asp:Label ID="Id_SucursalLabel1" runat="server" Text='<%# Eval("Id_Sucursal") %>' />
                                    <br />NombreSucursal:
                                    <asp:TextBox ID="NombreSucursalTextBox" runat="server" Text='<%# Bind("NombreSucursal") %>' />
                                    <br />DescripcionSucursal:
                                    <asp:TextBox ID="DescripcionSucursalTextBox" runat="server" Text='<%# Bind("DescripcionSucursal") %>' />
                                    <br />Id_HorarioSucursal:
                                    <asp:TextBox ID="Id_HorarioSucursalTextBox" runat="server" Text='<%# Bind("Id_HorarioSucursal") %>' />
                                    <br />Id_ProvinciaSucursal:
                                    <asp:TextBox ID="Id_ProvinciaSucursalTextBox" runat="server" Text='<%# Bind("Id_ProvinciaSucursal") %>' />
                                    <br />DireccionSucursal:
                                    <asp:TextBox ID="DireccionSucursalTextBox" runat="server" Text='<%# Bind("DireccionSucursal") %>' />
                                    <br />URL_Imagen_Sucursal:
                                    <asp:TextBox ID="URL_Imagen_SucursalTextBox" runat="server" Text='<%# Bind("URL_Imagen_Sucursal") %>' />
                                    <br />
                                    <asp:Button ID="UpdateButton" runat="server" CommandName="Update" Text="Actualizar" />
                                    <br />
                                    <asp:Button ID="CancelButton" runat="server" CommandName="Cancel" Text="Cancelar" />
                                    <br /></td>
                            </EditItemTemplate>
                            <EmptyDataTemplate>
                                <table runat="server" style="background-color: #FFFFFF;border-collapse: collapse;border-color: #999999;border-style:none;border-width:1px;">
                                    <tr>
                                        <td>No se han devuelto datos.</td>
                                    </tr>
                                </table>
                            </EmptyDataTemplate>
                            <EmptyItemTemplate>
<td runat="server" />
                            </EmptyItemTemplate>
                            <GroupTemplate>
                                <tr id="itemPlaceholderContainer" runat="server">
                                    <td id="itemPlaceholder" runat="server"></td>
                                </tr>
                            </GroupTemplate>
                            <InsertItemTemplate>
                                <td runat="server" style="">NombreSucursal:
                                    <asp:TextBox ID="NombreSucursalTextBox" runat="server" Text='<%# Bind("NombreSucursal") %>' />
                                    <br />DescripcionSucursal:
                                    <asp:TextBox ID="DescripcionSucursalTextBox" runat="server" Text='<%# Bind("DescripcionSucursal") %>' />
                                    <br />Id_HorarioSucursal:
                                    <asp:TextBox ID="Id_HorarioSucursalTextBox" runat="server" Text='<%# Bind("Id_HorarioSucursal") %>' />
                                    <br />Id_ProvinciaSucursal:
                                    <asp:TextBox ID="Id_ProvinciaSucursalTextBox" runat="server" Text='<%# Bind("Id_ProvinciaSucursal") %>' />
                                    <br />DireccionSucursal:
                                    <asp:TextBox ID="DireccionSucursalTextBox" runat="server" Text='<%# Bind("DireccionSucursal") %>' />
                                    <br />URL_Imagen_Sucursal:
                                    <asp:TextBox ID="URL_Imagen_SucursalTextBox" runat="server" Text='<%# Bind("URL_Imagen_Sucursal") %>' />
                                    <br />
                                    <asp:Button ID="InsertButton" runat="server" CommandName="Insert" Text="Insertar" />
                                    <br />
                                    <asp:Button ID="CancelButton" runat="server" CommandName="Cancel" Text="Borrar" />
                                    <br /></td>
                            </InsertItemTemplate>
                            <ItemTemplate>
                                <td runat="server" style="background-color: #E0FFFF;color: #333333; text-align: center;" class="auto-style11">&nbsp;<asp:Label ID="NombreSucursalLabel" runat="server" Font-Bold="True" Text='<%# Eval("NombreSucursal") %>'></asp:Label>
                                    <br />
                                    <asp:ImageButton ID="ImageButton1" runat="server" ImageUrl='<%# Eval("URL_Imagen_Sucursal") %>' Width="100px" />
                                    <br />
                                    <asp:Label ID="DescripcionSucursalLabel" runat="server" Text='<%# Eval("DescripcionSucursal") %>' />
                                    <br />
                                    <asp:Button ID="btnSeleccionar" runat="server" Text="Seleccionar" CommandArgument='<%# Bind("Id_Sucursal") %>' CommandName="eventoSeleccionar" OnCommand="btnSeleccionar_Command" />
                                    <br /></td>
                            </ItemTemplate>
                            <LayoutTemplate>
                                <table runat="server">
                                    <tr runat="server">
                                        <td runat="server">
                                            <table id="groupPlaceholderContainer" runat="server" border="1" style="background-color: #FFFFFF;border-collapse: collapse;border-color: #999999;border-style:none;border-width:1px;font-family: Verdana, Arial, Helvetica, sans-serif;">
                                                <tr id="groupPlaceholder" runat="server">
                                                </tr>
                                            </table>
                                        </td>
                                    </tr>
                                    <tr runat="server">
                                        <td runat="server" style="text-align: center;background-color: #5D7B9D;font-family: Verdana, Arial, Helvetica, sans-serif;color: #FFFFFF">
                                            <asp:DataPager ID="DataPager1" runat="server" PageSize="6">
                                                <Fields>
                                                    <asp:NextPreviousPagerField ButtonType="Button" ShowFirstPageButton="True" ShowNextPageButton="False" ShowPreviousPageButton="False" />
                                                    <asp:NumericPagerField />
                                                    <asp:NextPreviousPagerField ButtonType="Button" ShowLastPageButton="True" ShowNextPageButton="False" ShowPreviousPageButton="False" />
                                                </Fields>
                                            </asp:DataPager>
                                        </td>
                                    </tr>
                                </table>
                            </LayoutTemplate>
                            <SelectedItemTemplate>
                                <td runat="server" style="background-color: #E2DED6;font-weight: bold;color: #333333;">Id_Sucursal:
                                    <asp:Label ID="Id_SucursalLabel" runat="server" Text='<%# Eval("Id_Sucursal") %>' />
                                    <br />NombreSucursal:
                                    <asp:Label ID="NombreSucursalLabel" runat="server" Text='<%# Eval("NombreSucursal") %>' />
                                    <br />DescripcionSucursal:
                                    <asp:Label ID="DescripcionSucursalLabel" runat="server" Text='<%# Eval("DescripcionSucursal") %>' />
                                    <br />Id_HorarioSucursal:
                                    <asp:Label ID="Id_HorarioSucursalLabel" runat="server" Text='<%# Eval("Id_HorarioSucursal") %>' />
                                    <br />Id_ProvinciaSucursal:
                                    <asp:Label ID="Id_ProvinciaSucursalLabel" runat="server" Text='<%# Eval("Id_ProvinciaSucursal") %>' />
                                    <br />DireccionSucursal:
                                    <asp:Label ID="DireccionSucursalLabel" runat="server" Text='<%# Eval("DireccionSucursal") %>' />
                                    <br />URL_Imagen_Sucursal:
                                    <asp:Label ID="URL_Imagen_SucursalLabel" runat="server" Text='<%# Eval("URL_Imagen_Sucursal") %>' />
                                    <br /></td>
                            </SelectedItemTemplate>
                        </asp:ListView>
                    </td>
                    <td>&nbsp;</td>
                </tr>
            </table>
            <br />
        </div>
        <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:BDSucursalesConnectionString %>" SelectCommand="SELECT [Id_Sucursal], [NombreSucursal], [DescripcionSucursal], [Id_HorarioSucursal], [Id_ProvinciaSucursal], [DireccionSucursal], [URL_Imagen_Sucursal] FROM [Sucursal]"></asp:SqlDataSource>
    </form>
</body>
</html>
