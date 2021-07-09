package com.yasa.prak_oop;


import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Program_1 {
 String url, usr, pwd, db;

	 public Program_1(){
		 db = "db_191110227";
		 url = "jdbc:mysql://localhost/" + db;
		 usr = "root";
		 pwd = "";
	 }
	 public Connection getConnection() {
		 Connection con = null;
		 try {
			 Class.forName("com.mysql.jdbc.Driver");
			 con = DriverManager.getConnection(url, usr, pwd);
			 System.out.println("Ok : Driver Ditemukan");
		 }
		 catch (ClassNotFoundException e) {
			 System.out.println("Error: Driver Tidak Ditemukan \n"+e+"\n");
		 }
		 catch (SQLException e) {
			 System.out.println("Error:Tidak Bisa Koneksi Ke Database\n"+
			 e+"\n");
	 }
	 return con;
	 }
}


