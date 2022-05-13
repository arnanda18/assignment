<html>
    <head>
        <!-- CSS only -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" 
        integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
        
    </head>
    <body>  
        <style>
            @import url('https://fonts.googleapis.com/css2?family=Poppins:wght@300;400;500;600;700;800;900&display=swap');

            table{
                width: 100;
                height: 200;
                border: 2px solid;
            }
        </style>
        <div class="container-sm mt-4">
            <h2 class="col-sm-4 mb-4" style="text-align: center;">Form Add Biodata</h2>
        <form action="../config/insert.php" method="POST" enctype="multipart/form-data">
            <div class="row mb-3 ">
                <label class="col-sm-2 col-form-label">Nama Lengkap</label>
                <div class="col-sm-4">
                <input type="name" name="name" class="form-control">
                </div>
            </div>
            <div class="row mb-3 ">
                <label class="col-sm-2 form-label">Alamat</label>
                <div class="col-sm-4">
                <textarea class="col-sm-2 form-control" name="alamat" rows="3"></textarea>
                </div>
            </div>
            <div class="row form-group mb-2">
                        <label for="agama" class="col-sm-2 required">Agama</label>
                        <div class="col-sm-4">
                            <select class="col-sm-2 form-select" name="agama" id="agama" required>
                                <option value="Islam">Islam</option>
                                <option value="Budha">Budha</option>
                                <option value="Kristen">Kristen</option>
                                <option value="Konghucu">Konghucu</option>
                                <option value="Khatolik">Khatolik</option>
                                <option value="Hindu">Hindu</option>
                            </select>
                        </div>
             </div>
             <div class="row mb-3 ">
                <label class="col-sm-2 col-form-label">Tanggal Lahir</label>
                <div class="col-sm-4">
                <input type="date" name="ttl" class="form-control">
                </div>
            </div>
            <div class="row mb-3 ">
                <label class="col-sm-2 col-form-label">Pendidikan Terakhir</label>
                <div class="col-sm-4">
                <input type="alamat" name="pendidikan" class="form-control">
                </div>
            </div>
            <div class="row mb-3">
                <label class="col-sm-2 form-label">Jenis Kelamin</label>
                <div class="col-sm-4">
                    <div class="form-check form-check-inline">
                            <input class="col-sm-2 form-check-input" type="radio" name="genre" value="L">
                            <label class="col-sm-2 form-check-label">Male</label>
                    </div>
                    <div class="form-check form-check-inline">
                            <input class="col-sm-2 form-check-input" type="radio" name="genre" value="P">
                            <label class="col-sm-2 form-check-label">Female</label>
                    </div>
                </div>
            </div>
            <div class="row mb-3 ">
                <label class="col-sm-2 col-form-label">Program Studi</label>
                <div class="col-sm-4">
                <input type="alamat" name="prodi" class="form-control">
                </div>
            </div>
            <div class="row mb-3 ">
                <label class="col-sm-2 col-form-label">Hobbi</label>
                <div class="col-sm-4">
                <input type="hobbi" name="hobbi" class="form-control">
                </div>
            </div>
            <div class="row mb-3 ">
                <label class="col-sm-2 form-label">Keahlian/Skill</label>
                <div class="col-sm-4">
                <textarea class="col-sm-2 form-control" name="keahlian" rows="3"></textarea>
                </div>
            </div>
            <div class="row mb-3 ">
                <label class="col-sm-2 form-label">Pengalaman</label>
                <div class="col-sm-4">
                <textarea class="col-sm-2 form-control" name="pengalaman" rows="3"></textarea>
                </div>
            </div>
            <div class="row input-group mb-3">
                <label class="col-sm-2 input-group-text" for="input">Foto</label>
                <div class="col-sm-4">
                <input type="file" class="col-sm-2 form-control" id="input" name="pass_foto">
                </div>
            </div>
            <button type="submit" name="submit" class="btn btn-primary">Add Biodata</button>
        </form>
    </div>
</body>
</html>
