echo off
rem echo Usage:
rem echo ------
rem echo pack (shared | static) [vsvers] [release]       // pack shared 150 1.10.1 
rem echo ------
setlocal enableextensions enabledelayedexpansion
if "%1"=="" goto usage
if "%2"=="" goto usage
if "%3"=="" goto usage

del *.noarch.%3.nupkg *.%1.%3.nupkg *.%1.%3.symbols.nupkg

for %%G in (Data/SQLite Data/ODBC Data/MySQL Data/PostgreSQL Foundation Encodings XML JSON Util Net Crypto NetSSL_OpenSSL NetSSL_Win Data  Zip JWT PDF CppParser MongoDB Redis) do (
rem for %%G in (Foundation) do (
	@copy Poco.front foo
	if exist ..\..\..\%%G\dependencies (
		for /f "delims=" %%M in (..\..\..\%%G\dependencies) do (
			echo ^<dependency id='Poco.%%M.vs$vs$.%1' version='$version$' ^/^> >> foo
		)
	)
	@copy /y /b foo+Poco.%1.back  Poco.%1.nuspec
	set module=%%G
	set inc=%%G
	set macro=foobar
	if [%%G] == [Foundation] 		set module=Foundation		& set macro=FOUNDATION
	if [%%G] == [Encodings] 		set module=Encodings		& set macro=ENCODINGS
	if [%%G] == [XML] 				set module=XML				& set macro=XML
	if [%%G] == [JSON] 				set module=JSON				& set macro=JSON
	if [%%G] == [Util] 				set module=Util				& set macro=UTIL
	if [%%G] == [Net] 				set module=Net				& set macro=NET
	if [%%G] == [Crypto] 			set module=Crypto			& set macro=CRYPTO
	if [%%G] == [Data] 				set module=Data				& set macro=DATA
	if [%%G] == [Zip] 				set module=Zip				& set macro=ZIP
	if [%%G] == [JWT] 				set module=JWT				& set macro=JWT
	if [%%G] == [PDF] 				set module=PDF				& set macro=PDF
	if [%%G] == [CppParser] 		set module=CppParser		& set macro=CPPPARSER
	if [%%G] == [MongoDB] 			set module=MongoDB			& set macro=MONGODB
	if [%%G] == [Redis] 			set module=Redis			& set macro=REDIS
	if [%%G] == [NetSSL_OpenSSL] 	set module=NetSSL			& set macro=NETSSL
	if [%%G] == [NetSSL_Win] 		set module=NetSSLWin		& set macro=NETSSLWIN
	if [%%G] == [Data/SQLite] 		set module=DataSQLite		& set macro=DATASQLLITE		& set inc=Data\SQLite
	if [%%G] == [Data/ODBC] 		set module=DataODBC			& set macro=DATAODBC		& set inc=Data\ODBC
	if [%%G] == [Data/MySQL] 		set module=DataMySQL		& set macro=DATAMYSQL		& set inc=Data\MySQL
	if [%%G] == [Data/PostgreSQL] 	set module=DataPostgreSQL	& set macro=DATAPOSTGRESQL	& set inc=Data\PostgreSQL
	if [%1]  == [shared] (
		echo ^<?xml version="1.0" encoding="utf-8"?^> 														> Poco.shared.props
		echo ^<Project xmlns="http://schemas.microsoft.com/developer/msbuild/2003"^>						>> Poco.shared.props
		echo ^<PropertyGroup Label="UserMacros" Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'"^>	>> Poco.shared.props
		echo ^<!macro!^>^$^(MSBuildThisFileDirectory^)bin^\^</!macro!^>												>> Poco.shared.props
		echo ^</PropertyGroup^>	>> Poco.shared.props											
		echo ^<PropertyGroup Label="UserMacros" Condition="'$(Configuration)|$(Platform)'=='Debug|x86'"^>	>> Poco.shared.props
		echo ^<!macro!^>^$^(MSBuildThisFileDirectory^)bin^\^</!macro!^>												>> Poco.shared.props
		echo ^</PropertyGroup^>	>> Poco.shared.props
		echo ^<PropertyGroup Label="UserMacros" Condition="'$(Configuration)|$(Platform)'=='Debug|x64'"^>	>> Poco.shared.props
		echo ^<!macro!^>^$^(MSBuildThisFileDirectory^)bin64^\^</!macro!^>												>> Poco.shared.props
		echo ^</PropertyGroup^>	>> Poco.shared.props
		echo ^</Project^>	>> Poco.shared.props
	)
	call nuget pack Poco.noarch.nuspec 			-p vs=%2 -p version=%3 -p id=!module! -p inc=!inc!
	call nuget pack Poco.%1.nuspec 	-symbols 	-p vs=%2 -p version=%3 -p id=!module! -p inc=!inc! -p mode=%1 -verbosity detailed
rem	     nuget pack Poco.CppParser.nuspec -symbols -p vs=150 -p version=1.10.1 -p id=CppParser -p inc=CppParser -p mode=shared 
)

goto exit
:usage
echo Usage:
echo ------
echo "pack (shared | static) [vsvers] [release]"       // pack shared 150 1.10.1 
echo ------
:exit
endlocal
rem echo on