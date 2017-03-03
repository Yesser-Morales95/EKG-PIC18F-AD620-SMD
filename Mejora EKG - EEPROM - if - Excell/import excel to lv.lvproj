<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="10008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Ejemplos" Type="Folder">
			<Item Name="ejemplo.vi" Type="VI" URL="../ejemplo.vi"/>
		</Item>
		<Item Name="SV Cells automatico.vi" Type="VI" URL="../SV Cells automatico.vi"/>
		<Item Name="SV Cells.vi" Type="VI" URL="../SV Cells.vi"/>
		<Item Name="SV Close Excel.vi" Type="VI" URL="../SV Close Excel.vi"/>
		<Item Name="SV Close Work Sheet.vi" Type="VI" URL="../SV Close Work Sheet.vi"/>
		<Item Name="SV Close XLS.vi" Type="VI" URL="../SV Close XLS.vi"/>
		<Item Name="SV Open Excel.vi" Type="VI" URL="../SV Open Excel.vi"/>
		<Item Name="SV Open Work Sheet.vi" Type="VI" URL="../SV Open Work Sheet.vi"/>
		<Item Name="SV Open XLS.vi" Type="VI" URL="../SV Open XLS.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
			</Item>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
