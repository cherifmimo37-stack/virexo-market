const express = require("express");
const fs = require("fs");
const path = require("path");

const app = express();

const PORT = process.env.PORT || 3000;

const DB_FILE = path.join(
    __dirname,
    "database.json"
);


// ===============================
// MIDDLEWARE
// ===============================

app.use(express.json());

app.use(
    express.static(
        path.join(__dirname, "public")
    )
);


// ===============================
// DATABASE
// ===============================

function readDatabase() {

    try {

        if (!fs.existsSync(DB_FILE)) {

            return {
                settings: {
                    appName: "TABIBK",
                    whatsapp: "213671995831"
                },
                doctors: [],
                bookings: [],
                admins: []
            };

        }

        const data =
            fs.readFileSync(
                DB_FILE,
                "utf8"
            );

        return JSON.parse(data);

    }

    catch (error) {

        console.error(
            "Database error:",
            error
        );

        return {
            settings: {},
            doctors: [],
            bookings: [],
            admins: []
        };

    }

}


function saveDatabase(database) {

    fs.writeFileSync(

        DB_FILE,

        JSON.stringify(
            database,
            null,
            2
        ),

        "utf8"

    );

}


// ===============================
// TEST
// ===============================

app.get(
    "/api/health",
    (req, res) => {

        res.json({

            success: true,

            message:
                "TABIBK V3 Server يعمل بنجاح 🚀"

        });

    }
);


// ===============================
// GET DOCTORS
// ===============================

app.get(
    "/api/doctors",
    (req, res) => {

        const database =
            readDatabase();

        const doctors =
            database.doctors
            .filter(
                doctor =>
                    doctor.active !== false
            )
            .map(
                doctor => ({

                    id: doctor.id,

                    name: doctor.name,

                    specialty:
                        doctor.specialty,

                    phone:
                        doctor.phone,

                    clinic:
                        doctor.clinic,

                    experience:
                        doctor.experience,

                    rating:
                        doctor.rating

                })
            );

        res.json({

            success: true,

            doctors: doctors

        });

    }
);


// ===============================
// CREATE BOOKING
// ===============================

app.post(
    "/api/bookings",
    (req, res) => {

        const {

            patientName,

            patientPhone,

            specialty,

            doctorId,

            date,

            time,

            type,

            notes

        } = req.body;


        // =========================
        // VALIDATION
        // =========================

        if (

            !patientName ||
            !patientPhone ||
            !specialty ||
            !doctorId ||
            !date ||
            !time

        ) {

            return res.status(400).json({

                success: false,

                message:
                    "جميع معلومات الحجز المطلوبة ضرورية"

            });

        }


        const database =
            readDatabase();


        // =========================
        // FIND DOCTOR
        // =========================

        const doctor =
            database.doctors.find(
                d =>
                    Number(d.id) ===
                    Number(doctorId)
            );


        if (!doctor) {

            return res.status(404).json({

                success: false,

                message:
                    "الطبيب غير موجود"

            });

        }


        // =========================
        // BOOKING NUMBER
        // =========================

        const bookingNumber =
            "TAB-" +
            Math.floor(
                100000 +
                Math.random() *
                900000
            );


        // =========================
        // BOOKING
        // =========================

        const booking = {

            id: bookingNumber,

            patientName:
                patientName.trim(),

            patientPhone:
                patientPhone.trim(),

            specialty,

            doctorId:
                Number(doctorId),

            doctorName:
                doctor.name,

            clinic:
                doctor.clinic,

            date,

            time,

            type:
                type || "فحص واستشارة",

            notes:
                notes || "",

            status:
                "pending",

            createdAt:
                new Date().toISOString()

        };


        database.bookings.push(
            booking
        );


        saveDatabase(
            database
        );


        // =========================
        // RESPONSE
        // =========================

        res.status(201).json({

            success: true,

            message:
                "تم إنشاء الحجز بنجاح",

            booking

        });

    }
);


// ===============================
// GET BOOKING
// ===============================

app.get(
    "/api/bookings/:id",
    (req, res) => {

        const database =
            readDatabase();

        const booking =
            database.bookings.find(
                b =>
                    b.id ===
                    req.params.id
            );


        if (!booking) {

            return res.status(404).json({

                success: false,

                message:
                    "الحجز غير موجود"

            });

        }


        res.json({

            success: true,

            booking

        });

    }
);


// ===============================
// GET ALL BOOKINGS
// ===============================

app.get(
    "/api/bookings",
    (req, res) => {

        const database =
            readDatabase();

        res.json({

            success: true,

            bookings:
                database.bookings

        });

    }
);


// ===============================
// DOCTOR ACCEPT BOOKING
// ===============================

app.post(
    "/api/bookings/:id/accept",
    (req, res) => {

        const database =
            readDatabase();

        const booking =
            database.bookings.find(
                b =>
                    b.id ===
                    req.params.id
            );


        if (!booking) {

            return res.status(404).json({

                success: false,

                message:
                    "الحجز غير موجود"

            });

        }


        booking.status =
            "accepted";

        booking.updatedAt =
            new Date().toISOString();


        saveDatabase(
            database
        );


        res.json({

            success: true,

            message:
                "تم قبول الموعد ✅",

            booking

        });

    }
);


// ===============================
// DOCTOR REJECT BOOKING
// ===============================

app.post(
    "/api/bookings/:id/reject",
    (req, res) => {

        const database =
            readDatabase();

        const booking =
            database.bookings.find(
                b =>
                    b.id ===
                    req.params.id
            );


        if (!booking) {

            return res.status(404).json({

                success: false,

                message:
                    "الحجز غير موجود"

            });

        }


        booking.status =
            "rejected";

        booking.updatedAt =
            new Date().toISOString();


        saveDatabase(
            database
        );


        res.json({

            success: true,

            message:
                "تم رفض الموعد",

            booking

        });

    }
);


// ===============================
// CANCEL BOOKING
// ===============================

app.post(
    "/api/bookings/:id/cancel",
    (req, res) => {

        const database =
            readDatabase();

        const booking =
            database.bookings.find(
                b =>
                    b.id ===
                    req.params.id
            );


        if (!booking) {

            return res.status(404).json({

                success: false,

                message:
                    "الحجز غير موجود"

            });

        }


        booking.status =
            "cancelled";

        booking.updatedAt =
            new Date().toISOString();


        saveDatabase(
            database
        );


        res.json({

            success: true,

            message:
                "تم إلغاء الحجز",

            booking

        });

    }
);


// ===============================
// SERVER
// ===============================

app.listen(
    PORT,
    () => {

        console.log(
            `TABIBK V3 running on port ${PORT}`
        );

    }
);
