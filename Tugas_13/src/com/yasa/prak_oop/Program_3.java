package com.yasa.prak_oop;

import java.awt.*;
import javax.swing.*;
import java.sql.*;
import javax.swing.table.*;
import java.awt.event.*;

public class Program_3 extends JPanel {
	
	String[] header = {"nim","Nama"};
	JTable table_mhs = new JTable();
	JScrollPane scrollTable = new JScrollPane();
	public Object[][] isiTable = null;
	
	//Menu Bar
	private static final long serialVersionUID = 1L;
	
	JMenuBar mainMenu = new JMenuBar();
	JMenu File = new JMenu("File");
	JMenuItem inputData = new JMenuItem("Input Data");
	JMenuItem exit = new JMenuItem("Exit");
	
	JLabel label_nim = new JLabel("NIM	: 191110227");
	JLabel label_nama = new JLabel("Nama	: Arnanda Nuryasa");
	
	Program_3(){
		
		Program_1 open = new Program_1 ();
		Connection mysql = open.getConnection();
		try {
		 Statement stmt = mysql.createStatement();
		 String sql = "SELECT * FROM tbl_mhs";
		 ResultSet res = stmt.executeQuery(sql);
		 ResultSetMetaData meta = res.getMetaData();
		 int kolom = meta.getColumnCount();
		 int baris = 0;
		 while(res.next()) {
			 baris = res.getRow();
		 }
		 
		 isiTable = new Object[baris][kolom];
		 int x = 0;
		 res.beforeFirst();
		 while(res.next()) {
			 isiTable[x][0] = res.getString("NIM");
			 isiTable[x][1] = res.getString("Nama");
			 x++;
		 }
		 scrollTable.setViewportView(table_mhs);
		 table_mhs.setModel(new DefaultTableModel(isiTable,header));
		 add(scrollTable, BorderLayout.NORTH);
		 stmt.close();
		 res.close();
		}
		catch (Exception ex){
			JOptionPane.showMessageDialog(null, ex);
		}
	}
	void Layout() {
		 JFrame frame = new JFrame("Data Mahasiswa");
		 frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		 Program_3 content = new Program_3();
		 content.setOpaque(true);
		 frame.setContentPane(content);
		 frame.pack();
		 frame.setLocationRelativeTo(null);
		 
		 
		 
		 
		 //Menu Bar
		 frame.setJMenuBar(mainMenu);
		 mainMenu.add(File);
		 File.add(inputData);
		 File.add(exit);
		 
		 frame.setLayout(null);
		 frame.setSize(700, 400);
		 frame.getContentPane().add(label_nim).setBounds(480,120,280,40);
		 frame.getContentPane().add(label_nama).setBounds(480,150,280,40);
		 
		 frame.setVisible(true);
		 	 
		 
	}
	
	void Action() {
		
		inputData.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Program_2 inputData = new Program_2();
				inputData.Action();
				inputData.Layout();
			}
		});

		
		exit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});
		
		
		
	}
	public static void main(String [] args){
		Program_3 run = new Program_3();
		run.Layout();
		run.Action();
	}
}
