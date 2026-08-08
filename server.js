const express = require("express");
const path = require("path");
const fs = require("fs");

const app = express();

const PORT = process.env.PORT || 3000;

const DATABASE_FILE = path.join(__dirname, "database.json");

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.use(express.static(path.join(__dirname, "public")));


// ================= DATABASE =================

function readDatabase() {
  try {
    if (!fs.existsSync(DATABASE_FILE)) {
      return {
        users: [],
        products: []
      };
    }

    const data = fs.readFileSync(
      DATABASE_FILE,
      "utf8"
    );

    return JSON.parse(data);

  } catch (error) {

    console.error("Database read error:", error);

    return {
      users: [],
      products: []
    };
  }
}


function saveDatabase(database) {

  fs.writeFileSync(
    DATABASE_FILE,
    JSON.stringify(database, null, 2),
    "utf8"
  );

}


// ================= HOME =================

app.get("/", (req, res) => {

  res.sendFile(
    path.join(
      __dirname,
      "public",
      "index.html"
    )
  );

});


// ================= API STATUS =================

app.get("/api/status", (req, res) => {

  res.json({
    success: true,
    message: "Virexo Market API تعمل بنجاح 🚀",
    version: "2.0.0"
  });

});


// ================= GET PRODUCTS =================

app.get("/api/products", (req, res) => {

  const database = readDatabase();

  res.json({
    success: true,
    products: database.products
  });

});


// ================= ADD PRODUCT =================

app.post("/api/products", (req, res) => {

  const database = readDatabase();

  const {
    name,
    price,
    category,
    wilaya,
    commune,
    seller,
    phone,
    description,
    image
  } = req.body;


  if (!name || !price || !category || !wilaya || !seller || !phone) {

    return res.status(400).json({

      success: false,

      message: "يرجى ملء جميع المعلومات المطلوبة"

    });

  }


  const product = {

    id: Date.now(),

    name: String(name).trim(),

    price: Number(price),

    category: String(category).trim(),

    wilaya: String(wilaya).trim(),

    commune: String(commune || "").trim(),

    seller: String(seller).trim(),

    phone: String(phone).trim(),

    description: String(description || "").trim(),

    image: image || "",

    date: Date.now()

  };


  database.products.unshift(product);

  saveDatabase(database);


  res.status(201).json({

    success: true,

    message: "تم نشر السلعة بنجاح 🎉",

    product

  });

});


// ================= GET SINGLE PRODUCT =================

app.get("/api/products/:id", (req, res) => {

  const database = readDatabase();

  const id = Number(req.params.id);

  const product =
    database.products.find(
      item => item.id === id
    );


  if (!product) {

    return res.status(404).json({

      success: false,

      message: "الإعلان غير موجود"

    });

  }


  res.json({

    success: true,

    product

  });

});


// ================= DELETE PRODUCT =================

app.delete("/api/products/:id", (req, res) => {

  const database = readDatabase();

  const id = Number(req.params.id);


  const oldLength =
    database.products.length;


  database.products =
    database.products.filter(
      item => item.id !== id
    );


  if (
    database.products.length === oldLength
  ) {

    return res.status(404).json({

      success: false,

      message: "الإعلان غير موجود"

    });

  }


  saveDatabase(database);


  res.json({

    success: true,

    message: "تم حذف الإعلان"

  });

});


// ================= START SERVER =================

app.listen(PORT, "0.0.0.0", () => {
  console.log(`Virexo Market running on port ${PORT}`);
});
