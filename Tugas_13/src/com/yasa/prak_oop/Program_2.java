package com.yasa.prak_oop;


import java.awt.event.*;
import javax.swing.*;
import java.sql.Connection;
import java.awt.*;
import java.sql.*;

//Author : Arnanda Nuryasa

public class Program_2 extends JFrame {
	
	 JLabel label_NIM=new JLabel("NIM");
	 JTextField txt_NIM=new JTextField(30);
	 JLabel label_Nama=new JLabel("Name");
	 JTextField txt_Nama=new JTextField(50);
	 JButton buttonSearch=new JButton("Search");
	 JButton buttonSave=new JButton("Save");
	 JButton buttonUpdate=new JButton("Update");
	 JButton buttonDelete=new JButton("Delete");
	 JButton buttonExit = new JButton("Exit");
	 
	 //Nim and Name
	 JLabel label_inim=new JLabel("NIM	: 191110227");
	 JLabel label_iname=new JLabel("Name	: Arnanda Nuryasa");
	 
	 Program_2 (){
		 setTitle("Data Mahasiswa");
		 setLocation(300,100);
		 setSize(500,350);
		 setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	 }
	 
	 void Layout(){
		 getContentPane().setLayout(null);
		 
		 getContentPane().add(label_NIM).setBounds(10,10,70,20);
		 
		 getContentPane().add(txt_NIM).setBounds(80,10,110,20);
		 getContentPane().add(buttonSearch).setBounds(200,10,80,20);
		 getContentPane().add(label_Nama).setBounds(10,40,70,20);
		 getContentPane().add(txt_Nama).setBounds(80,40,200,20);
		 getContentPane().add(buttonSave).setBounds(10,80,80,20);
		 getContentPane().add(buttonUpdate).setBounds(105,80,80,20);
		 getContentPane().add(buttonDelete).setBounds(200,80,80,20);
		 getContentPane().add(buttonExit).setBounds(300,80,80,20);
		 
		 
		 getContentPane().add(label_inim).setBounds(10,120,280,40);
		 getContentPane().add(label_iname).setBounds(10,150,280,40);
		 setVisible(true);
		 
	 }
	 
	 void Action(){
	 //button Save
	buttonSave.addActionListener(new ActionListener(){
			 public void actionPerformed (ActionEvent e){
				Program_1 open = new Program_1();
				Connection mysql = open.getConnection();
				try {
				 Statement stmt = mysql.createStatement();
				 String sql = "INSERT INTO tbl_mhs VALUES ('"+txt_NIM.getText()+"','"+txt_Nama.getText()+"');";
				 int i = stmt.executeUpdate (sql);
				 if (i == 1) {
					 JOptionPane.showMessageDialog(null,"Data Sudah Disimpan");
				 }
				}
				catch (Exception ex){
				 JOptionPane.showMessageDialog(null, ex.getMessage());
					}
				 }
	 });

	 // button search
	 buttonSearch.addActionListener(new ActionListener(){
		 public void actionPerformed (ActionEvent e){
			String search;
			Program_1 open = new Program_1 ();
			Connection mysql = open.getConnection();
			try {
				 search=txt_NIM.getText();
				 Statement stmt = mysql.createStatement();
				 String sql = "SELECT * FROM tbl_mhs "+ "WHERE NIM like '"+search+"'";
				 ResultSet res = stmt.executeQuery (sql);
				 if(res.next()){
					 txt_NIM.setText(res.getString(1));
					 txt_Nama.setText(res.getString(2));
				 }
				 else{
					 JOptionPane.showMessageDialog(null,"Data Sudah Ada");
			 }
			}
			catch (Exception ex){
				JOptionPane.showMessageDialog(null, ex.getMessage());
			}
		 }
	 });
	 // button update
	 buttonUpdate.addActionListener(new ActionListener() {
		public void actionPerformed (ActionEvent e) {
			Program_1 open = new Program_1 ();
			Connection mysql = open.getConnection();
			try {
				 Statement stmt = mysql.createStatement();
				 String sql = "UPDATE tbl_mhs SET "+"Nama='"+txt_Nama.getText()+"'"+"WHERE "+"NIM='"+txt_NIM.getText()+"'";
				 int i = stmt.executeUpdate (sql);
				 if (i == 1) {
					 JOptionPane.showMessageDialog(null,"Data Sudah Diupdate");
				 }
			} 
			catch (Exception ex){
				JOptionPane.showMessageDialog(null, ex.getMessage());
			}
		 	}
	 });
	 // button delete
	 buttonDelete.addActionListener(new ActionListener() {
		public void actionPerformed (ActionEvent e) {
			Program_1 open = new Program_1 ();
			Connection mysql = open.getConnection();
			try {
				 Statement stmt = mysql.createStatement();
				 String sql = "DELETE FROM tbl_mhs "+"WHERE NIM='"+txt_NIM.getText()+"'";
				 int i = stmt.executeUpdate (sql);
				 if (i == 1) {
					 JOptionPane.showMessageDialog(null,"Data Sudah Dihapus");
				 }
			}
			catch (Exception ex){
				JOptionPane.showMessageDialog(null, ex.getMessage());
			}
		}
	 });
	 buttonExit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});
		
	}
	public static void main(String[]args){
		Program_2 run = new Program_2();
		run.Layout();
		run.Action();
	}
}