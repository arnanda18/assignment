<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Dashboard</title>
</head>
<body>
	<?php
		if (isset($this->session->userdata['logged_in'])) {

			$username = ($this->session->userdata['logged_in']['username']);
			$full_name = ($this->session->userdata['logged_in']['full_name']);
			$email = ($this->session->userdata['logged_in']['email']);
			$role = ($this->session->userdata['logged_in']['role']);

			} else {

			header("location: login");
		}
	?>

	<h2>Dashboard</h2>
	<p><stong>Welcome admin !</strong>
		<?php echo $username; ?> <br />
	</p>
	<p>Username : <?php echo $username; ?></p> 
	<p>Full Name :<?php echo $full_name; ?></p>
	<p>Email :<?php echo $email; ?></p>
	<p>Level :<?php echo $role; ?></p>
	[<a href="http://localhost/PrakWeb8/index.php/login/logout">Logout</a>]
</body>
</html>
