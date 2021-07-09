package com.yasa.prak_oop;


import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Program_1 {
 String url, usr, pwd, db;

 public Program_1(){
	 db = "tbl_mhs";
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
 private void PembuatDialog(){
	 System.out.println("Created By : Yasa ~ http://linux-dev.xyz");
	 System.out.print("NIM	: 191110227 ,");
	 System.out.print("Nama	: Arnanda Nuryasa");
			 System.exit(0);
			 }
			 public static void main(String[] args){
				 Program_1 dnd = new Program_1();
				 dnd.getConnection();
				 dnd.PembuatDialog();
				 
				
			 }

 }


