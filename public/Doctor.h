<!DOCTYPE html>
<html lang="ar" dir="rtl">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>TABIBK | لوحة الطبيب</title>

    <link
        href="https://fonts.googleapis.com/css2?family=Cairo:wght@400;500;600;700;800;900&display=swap"
        rel="stylesheet"
    >

    <link
        rel="stylesheet"
        href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.2/css/all.min.css"
    >

    <style>

        * {
            box-sizing: border-box;
            margin: 0;
            padding: 0;
        }

        :root {
            --blue: #087fce;
            --blue-dark: #0565a5;
            --blue-light: #eaf6ff;

            --gold: #d6a928;
            --gold-light: #fff8df;

            --green: #19a974;
            --red: #e74c3c;
            --orange: #f39c12;

            --dark: #172333;
            --text: #334155;
            --muted: #7b8794;

            --bg: #f4f8fb;
            --white: #ffffff;

            --border: #e6edf3;

            --shadow:
                0 10px 35px rgba(20, 60, 90, .08);

            --radius: 20px;
        }

        body {
            font-family: "Cairo", sans-serif;
            background:
                linear-gradient(
                    180deg,
                    #eef8ff 0,
                    #f7fafc 300px,
                    #f4f8fb 100%
                );
            color: var(--text);
            min-height: 100vh;
        }

        button,
        input,
        select {
            font-family: inherit;
        }

        button {
            cursor: pointer;
        }

        /* =========================
           LOGIN
        ========================= */

        #loginPage {
            min-height: 100vh;
            display: flex;
            align-items: center;
            justify-content: center;
            padding: 20px;
        }

        .login-container {
            width: 100%;
            max-width: 430px;
            background: white;
            border-radius: 30px;
            padding: 32px 25px;
            box-shadow:
                0 25px 70px rgba(0, 80, 130, .13);
            border: 1px solid rgba(255,255,255,.8);
        }

        .login-logo {
            width: 82px;
            height: 82px;
            margin: 0 auto 15px;
            border-radius: 24px;
            background:
                linear-gradient(
                    145deg,
                    var(--blue),
                    #12a8ed
                );
            color: white;
            display: flex;
            align-items: center;
            justify-content: center;
            font-size: 38px;
            box-shadow:
                0 12px 30px rgba(8,127,206,.25);
        }

        .login-title {
            text-align: center;
            font-size: 27px;
            font-weight: 900;
            color: var(--dark);
        }

        .login-title span {
            color: var(--blue);
        }

        .login-subtitle {
            text-align: center;
            color: var(--muted);
            margin: 5px 0 28px;
            font-size: 14px;
        }

        .input-group {
            margin-bottom: 17px;
        }

        .input-group label {
            display: block;
            margin-bottom: 7px;
            font-size: 13px;
            font-weight: 700;
            color: var(--dark);
        }

        .input-wrapper {
            position: relative;
        }

        .input-wrapper i {
            position: absolute;
            right: 15px;
            top: 50%;
            transform: translateY(-50%);
            color: var(--blue);
        }

        .input-wrapper input {
            width: 100%;
            height: 52px;
            border: 1px solid var(--border);
            border-radius: 15px;
            outline: none;
            padding:
                0 45px
                0 15px;
            background: #fbfdff;
            transition: .25s;
            font-size: 14px;
        }

        .input-wrapper input:focus {
            border-color: var(--blue);
            box-shadow:
                0 0 0 4px rgba(8,127,206,.09);
            background: white;
        }

        .login-btn {
            width: 100%;
            height: 55px;
            border: none;
            border-radius: 16px;
            color: white;
            font-size: 16px;
            font-weight: 800;
            background:
                linear-gradient(
                    135deg,
                    var(--blue),
                    #06a7e8
                );
            box-shadow:
                0 10px 25px rgba(8,127,206,.25);
            transition: .25s;
        }

        .login-btn:hover {
            transform: translateY(-2px);
        }

        .login-btn i {
            margin-left: 7px;
        }

        .login-error {
            display: none;
            margin-top: 14px;
            padding: 11px;
            border-radius: 12px;
            background: #fff0ef;
            color: var(--red);
            font-size: 13px;
            text-align: center;
        }

        .demo-info {
            margin-top: 22px;
            padding: 13px;
            border-radius: 14px;
            background: var(--gold-light);
            border: 1px solid #f1dfa0;
            font-size: 12px;
            color: #806514;
            text-align: center;
        }

        /* =========================
           DASHBOARD
        ========================= */

        #dashboard {
            display: none;
            min-height: 100vh;
        }

        .top-header {
            position: sticky;
            top: 0;
            z-index: 50;
            height: 76px;
            background:
                rgba(255,255,255,.94);
            backdrop-filter: blur(15px);
            border-bottom:
                1px solid var(--border);
            display: flex;
            align-items: center;
            justify-content: space-between;
            padding: 0 22px;
        }

        .brand {
            display: flex;
            align-items: center;
            gap: 10px;
        }

        .brand-icon {
            width: 43px;
            height: 43px;
            border-radius: 13px;
            background:
                linear-gradient(
                    135deg,
                    var(--blue),
                    #11a8eb
                );
            color: white;
            display: flex;
            align-items: center;
            justify-content: center;
            font-size: 21px;
            box-shadow:
                0 7px 18px rgba(8,127,206,.2);
        }

        .brand-text {
            font-size: 21px;
            font-weight: 900;
            color: var(--dark);
        }

        .brand-text span {
            color: var(--blue);
        }

        .header-actions {
            display: flex;
            align-items: center;
            gap: 9px;
        }

        .icon-btn {
            width: 42px;
            height: 42px;
            border-radius: 13px;
            border: 1px solid var(--border);
            background: white;
            color: var(--text);
            display: flex;
            align-items: center;
            justify-content: center;
            position: relative;
            transition: .2s;
        }

        .icon-btn:hover {
            color: var(--blue);
            border-color: #b9ddf2;
        }

        .notification-dot {
            position: absolute;
            top: 7px;
            left: 7px;
            width: 8px;
            height: 8px;
            background: var(--red);
            border-radius: 50%;
            border: 2px solid white;
            display: none;
        }

        .doctor-mini {
            display: flex;
            align-items: center;
            gap: 8px;
            margin-right: 8px;
        }

        .doctor-avatar {
            width: 42px;
            height: 42px;
            border-radius: 50%;
            background:
                linear-gradient(
                    135deg,
                    #e7f5ff,
                    #ccecff
                );
            color: var(--blue);
            display: flex;
            align-items: center;
            justify-content: center;
            font-size: 19px;
            border: 2px solid white;
            box-shadow:
                0 4px 15px rgba(0,0,0,.06);
        }

        .main {
            max-width: 1250px;
            margin: auto;
            padding: 25px 18px 40px;
        }

        .welcome {
            border-radius: 25px;
            padding: 25px;
            color: white;
            background:
                radial-gradient(
                    circle at top left,
                    rgba(255,255,255,.2),
                    transparent 35%
                ),
                linear-gradient(
                    135deg,
                    #087fce,
                    #075f9d
                );
            box-shadow:
                0 15px 40px rgba(8,127,206,.17);
            display: flex;
            justify-content: space-between;
            align-items: center;
            gap: 20px;
            margin-bottom: 22px;
        }

        .welcome h1 {
            font-size: 24px;
            font-weight: 900;
            margin-bottom: 4px;
        }

        .welcome p {
            opacity: .9;
            font-size: 13px;
        }

        .online-box {
            background:
                rgba(255,255,255,.13);
            border:
                1px solid rgba(255,255,255,.2);
            padding: 12px 15px;
            border-radius: 16px;
            display: flex;
            align-items: center;
            gap: 10px;
        }

        .online-status {
            width: 11px;
            height: 11px;
            border-radius: 50%;
            background: #ffcc00;
            box-shadow:
                0 0 0 5px rgba(255,204,0,.14);
        }

        /* =========================
           STATS
        ========================= */

        .stats {
            display: grid;
            grid-template-columns:
                repeat(4, 1fr);
            gap: 15px;
            margin-bottom: 22px;
        }

        .stat-card {
            background: white;
            border: 1px solid var(--border);
            border-radius: 20px;
            padding: 19px;
            box-shadow: var(--shadow);
            display: flex;
            align-items: center;
            gap: 14px;
        }

        .stat-icon {
            width: 48px;
            height: 48px;
            border-radius: 15px;
            display: flex;
            align-items: center;
            justify-content: center;
            font-size: 20px;
        }

        .stat-icon.pending {
            background: #fff6df;
            color: var(--orange);
        }

        .stat-icon.accepted {
            background: #e9fbf4;
            color: var(--green);
        }

        .stat-icon.rejected {
            background: #fff0ef;
            color: var(--red);
        }

        .stat-icon.total {
            background: var(--blue-light);
            color: var(--blue);
        }

        .stat-label {
            color: var(--muted);
            font-size: 12px;
            font-weight: 600;
        }

        .stat-number {
            font-size: 25px;
            font-weight: 900;
            color: var(--dark);
            line-height: 1.3;
        }

        /* =========================
           CONTENT
        ========================= */

        .content-grid {
            display: grid;
            grid-template-columns:
                1fr 310px;
            gap: 20px;
            align-items: start;
        }

        .panel {
            background: white;
            border: 1px solid var(--border);
            border-radius: 22px;
            box-shadow: var(--shadow);
            overflow: hidden;
        }

        .panel-header {
            padding: 19px 20px;
            border-bottom:
                1px solid var(--border);
            display: flex;
            justify-content: space-between;
            align-items: center;
            gap: 10px;
        }

        .panel-title {
            font-size: 17px;
            font-weight: 900;
            color: var(--dark);
            display: flex;
            align-items: center;
            gap: 8px;
        }

        .panel-title i {
            color: var(--blue);
        }

        /* FILTERS */

        .filters {
            padding: 15px 18px;
            display: flex;
            gap: 8px;
            overflow-x: auto;
            border-bottom:
                1px solid var(--border);
        }

        .filter-btn {
            white-space: nowrap;
            border: 1px solid var(--border);
            background: white;
            color: var(--muted);
            border-radius: 11px;
            padding: 8px 13px;
            font-size: 12px;
            font-weight: 700;
        }

        .filter-btn.active {
            color: white;
            background: var(--blue);
            border-color: var(--blue);
        }

        /* BOOKING */

        #bookingsList {
            padding: 15px;
        }

        .booking-card {
            border: 1px solid var(--border);
            border-radius: 18px;
            padding: 17px;
            margin-bottom: 12px;
            transition: .2s;
            background: #fff;
        }

        .booking-card:hover {
            border-color: #c8e5f5;
            box-shadow:
                0 8px 25px rgba(20,80,110,.06);
        }

        .booking-top {
            display: flex;
            justify-content: space-between;
            align-items: flex-start;
            gap: 10px;
            margin-bottom: 13px;
        }

        .patient {
            display: flex;
            align-items: center;
            gap: 11px;
        }

        .patient-avatar {
            width: 46px;
            height: 46px;
            border-radius: 14px;
            background: var(--blue-light);
            color: var(--blue);
            display: flex;
            align-items: center;
            justify-content: center;
            font-size: 19px;
        }

        .patient-name {
            font-weight: 900;
            color: var(--dark);
            font-size: 14px;
        }

        .booking-id {
            color: var(--muted);
            font-size: 10px;
            margin-top: 2px;
        }

        .status {
            padding: 5px 9px;
            border-radius: 8px;
            font-size: 10px;
            font-weight: 800;
            white-space: nowrap;
        }

        .status.pending {
            background: #fff5dc;
            color: #bd7d00;
        }

        .status.accepted {
            background: #e7faf2;
            color: #12815a;
        }

        .status.rejected {
            background: #fff0ef;
            color: #c8392e;
        }

        .status.completed {
            background: #eaf6ff;
            color: #0872b9;
        }

        .status.cancelled {
            background: #f1f3f5;
            color: #707880;
        }

        .booking-info {
            display: grid;
            grid-template-columns:
                repeat(2, 1fr);
            gap: 8px;
            margin-bottom: 13px;
        }

        .info-item {
            padding: 10px;
            border-radius: 12px;
            background: #f8fafc;
            font-size: 11px;
        }

        .info-item i {
            color: var(--blue);
            margin-left: 5px;
        }

        .info-label {
            color: var(--muted);
            display: block;
            font-size: 9px;
            margin-bottom: 2px;
        }

        .info-value {
            font-weight: 700;
            color: var(--text);
        }

        .notes {
            background: #fffdf4;
            border:
                1px solid #f5e8b5;
            padding: 10px;
            border-radius: 12px;
            margin-bottom: 12px;
            font-size: 11px;
            color: #79642a;
        }

        .booking-actions {
            display: flex;
            gap: 8px;
            flex-wrap: wrap;
        }

        .action-btn {
            min-height: 40px;
            border: none;
            border-radius: 11px;
            padding: 8px 13px;
            font-size: 11px;
            font-weight: 800;
            display: inline-flex;
            align-items: center;
            justify-content: center;
            gap: 6px;
            transition: .2s;
        }

        .action-btn:hover {
            transform: translateY(-1px);
        }

        .accept-btn {
            color: white;
            background: var(--green);
            flex: 1;
        }

        .reject-btn {
            color: white;
            background: var(--red);
            flex: 1;
        }

        .complete-btn {
            color: white;
            background: var(--blue);
            flex: 1;
        }

        .whatsapp-btn {
            color: #16844e;
            background: #e8f9f0;
            border:
                1px solid #c9eddc;
        }

        /* EMPTY */

        .empty {
            padding: 55px 20px;
            text-align: center;
            color: var(--muted);
        }

        .empty i {
            font-size: 45px;
            color: #cbd7df;
            margin-bottom: 13px;
        }

        .empty h3 {
            color: var(--dark);
            font-size: 15px;
            margin-bottom: 4px;
        }

        .empty p {
            font-size: 12px;
        }

        /* SIDE */

        .side-card {
            background: white;
            border: 1px solid var(--border);
            border-radius: 20px;
            padding: 19px;
            box-shadow: var(--shadow);
            margin-bottom: 15px;
        }

        .profile {
            text-align: center;
        }

        .profile-avatar {
            width: 80px;
            height: 80px;
            margin: 3px auto 10px;
            border-radius: 25px;
            background:
                linear-gradient(
                    135deg,
                    #e6f5ff,
                    #c9ebff
                );
            color: var(--blue);
            display: flex;
            align-items: center;
            justify-content: center;
            font-size: 35px;
        }

        .profile h2 {
            font-size: 17px;
            color: var(--dark);
            font-weight: 900;
        }

        .profile-specialty {
            color: var(--blue);
            font-size: 12px;
            font-weight: 700;
            margin-top: 2px;
        }

        .profile-rating {
            margin-top: 8px;
            color: #d99b00;
            font-size: 12px;
        }

        .side-title {
            font-size: 14px;
            font-weight: 900;
            color: var(--dark);
            margin-bottom: 13px;
        }

        .side-row {
            display: flex;
            align-items: center;
            justify-content: space-between;
            padding: 10px 0;
            border-bottom:
                1px solid #eef2f5;
            font-size: 11px;
            gap: 10px;
        }

        .side-row:last-child {
            border-bottom: none;
            padding-bottom: 0;
        }

        .side-row span:first-child {
            color: var(--muted);
        }

        .side-row strong {
            color: var(--dark);
            text-align: left;
        }

        .logout-btn {
            width: 100%;
            height: 45px;
            border: none;
            border-radius: 13px;
            background: #fff0ef;
            color: var(--red);
            font-weight: 800;
            font-size: 12px;
        }

        /* LOADING */

        .loading {
            padding: 45px;
            text-align: center;
            color: var(--muted);
        }

        .loading i {
            font-size: 30px;
            color: var(--blue);
            animation: spin 1s linear infinite;
        }

        @keyframes spin {
            to {
                transform: rotate(360deg);
            }
        }

        /* TOAST */

        #toast {
            position: fixed;
            bottom: 22px;
            right: 18px;
            left: 18px;
            max-width: 420px;
            margin: auto;
            z-index: 999;
            background: #172333;
            color: white;
            border-radius: 15px;
            padding: 14px 16px;
            display: flex;
            align-items: center;
            gap: 9px;
            box-shadow:
                0 15px 40px rgba(0,0,0,.2);
            transform:
                translateY(120px);
            opacity: 0;
            transition: .3s;
            font-size: 12px;
        }

        #toast.show {
            transform: translateY(0);
            opacity: 1;
        }

        #toast.success i {
            color: #35d996;
        }

        #toast.error i {
            color: #ff756b;
        }

        /* RESPONSIVE */

        @media (max-width: 900px) {

            .content-grid {
                grid-template-columns: 1fr;
            }

            .side-column {
                display: grid;
                grid-template-columns:
                    repeat(2, 1fr);
                gap: 15px;
            }

            .side-card {
                margin-bottom: 0;
            }
        }

        @media (max-width: 650px) {

            .top-header {
                padding: 0 12px;
                height: 68px;
            }

            .brand-text {
                font-size: 18px;
            }

            .doctor-mini {
                display: none;
            }

            .main {
                padding:
                    15px 10px 30px;
            }

            .welcome {
                padding: 19px;
                border-radius: 20px;
                align-items: flex-start;
                flex-direction: column;
            }

            .welcome h1 {
                font-size: 20px;
            }

            .online-box {
                width: 100%;
                justify-content: center;
            }

            .stats {
                grid-template-columns:
                    repeat(2, 1fr);
                gap: 10px;
            }

            .stat-card {
                padding: 13px;
                gap: 9px;
            }

            .stat-icon {
                width: 40px;
                height: 40px;
                font-size: 17px;
            }

            .stat-number {
                font-size: 21px;
            }

            .booking-info {
                grid-template-columns:
                    1fr 1fr;
            }

            .side-column {
                grid-template-columns: 1fr;
            }

            .side-card {
                margin-bottom: 12px;
            }
        }

        @media (max-width: 390px) {

            .booking-info {
                grid-template-columns: 1fr;
            }

            .booking-actions {
                flex-direction: column;
            }

            .action-btn {
                width: 100%;
            }
        }

    </style>

</head>

<body>


<!-- =====================================================
     LOGIN
===================================================== -->

<section id="loginPage">

    <div class="login-container">

        <div class="login-logo">
            <i class="fa-solid fa-user-doctor"></i>
        </div>

        <h1 class="login-title">
            TABI<span>BK</span>
        </h1>

        <p class="login-subtitle">
            لوحة الطبيب وإدارة المواعيد
        </p>


        <form id="loginForm">

            <div class="input-group">

                <label>
                    رقم الطبيب
                </label>

                <div class="input-wrapper">

                    <i class="fa-solid fa-id-card"></i>

                    <input
                        id="doctorId"
                        type="number"
                        placeholder="مثال: 1"
                        required
                    >

                </div>

            </div>


            <div class="input-group">

                <label>
                    كلمة المرور
                </label>

                <div class="input-wrapper">

                    <i class="fa-solid fa-lock"></i>

                    <input
                        id="doctorPassword"
                        type="password"
                        placeholder="أدخل كلمة المرور"
                        required
                    >

                </div>

            </div>


            <button
                class="login-btn"
                type="submit"
            >

                <i class="fa-solid fa-right-to-bracket"></i>

                دخول لوحة الطبيب

            </button>

        </form>


        <div
            id="loginError"
            class="login-error"
        ></div>


        <div class="demo-info">

            <i class="fa-solid fa-circle-info"></i>

            للتجربة:
            الطبيب رقم
            <strong>1</strong>
            —
            كلمة المرور
            <strong>123456</strong>

        </div>

    </div>

</section>



<!-- =====================================================
     DASHBOARD
===================================================== -->

<section id="dashboard">


    <!-- HEADER -->

    <header class="top-header">

        <div class="brand">

            <div class="brand-icon">

                <i class="fa-solid fa-heart-pulse"></i>

            </div>

            <div class="brand-text">

                TABI<span>BK</span>

            </div>

        </div>


        <div class="header-actions">

            <button
                class="icon-btn"
                onclick="refreshBookings()"
                title="تحديث"
            >

                <i class="fa-solid fa-rotate"></i>

            </button>


            <button
                class="icon-btn"
                onclick="scrollToPending()"
                title="المواعيد الجديدة"
            >

                <i class="fa-solid fa-bell"></i>

                <span
                    id="notificationDot"
                    class="notification-dot"
                ></span>

            </button>


            <div class="doctor-mini">

                <div
                    id="headerAvatar"
                    class="doctor-avatar"
                >

                    <i class="fa-solid fa-user-doctor"></i>

                </div>

            </div>

        </div>

    </header>



    <!-- MAIN -->

    <main class="main">


        <!-- WELCOME -->

        <section class="welcome">

            <div>

                <h1 id="welcomeName">
                    مرحباً دكتور 👨‍⚕️
                </h1>

                <p>
                    تابع مواعيد مرضاك وأدر الحجوزات بسهولة.
                </p>

            </div>


            <div class="online-box">

                <span
                    class="online-status"
                    id="onlineIndicator"
                ></span>

                <strong id="onlineText">
                    متصل الآن
                </strong>

            </div>

        </section>



        <!-- STATS -->

        <section class="stats">


            <div class="stat-card">

                <div class="stat-icon pending">

                    <i class="fa-solid fa-hourglass-half"></i>

                </div>

                <div>

                    <div class="stat-label">
                        قيد الانتظار
                    </div>

                    <div
                        id="pendingCount"
                        class="stat-number"
                    >
                        0
                    </div>

                </div>

            </div>



            <div class="stat-card">

                <div class="stat-icon accepted">

                    <i class="fa-solid fa-circle-check"></i>

                </div>

                <div>

                    <div class="stat-label">
                        المقبولة
                    </div>

                    <div
                        id="acceptedCount"
                        class="stat-number"
                    >
                        0
                    </div>

                </div>

            </div>



            <div class="stat-card">

                <div class="stat-icon rejected">

                    <i class="fa-solid fa-circle-xmark"></i>

                </div>

                <div>

                    <div class="stat-label">
                        المرفوضة
                    </div>

                    <div
                        id="rejectedCount"
                        class="stat-number"
                    >
                        0
                    </div>

                </div>

            </div>



            <div class="stat-card">

                <div class="stat-icon total">

                    <i class="fa-solid fa-calendar-days"></i>

                </div>

                <div>

                    <div class="stat-label">
                        إجمالي المواعيد
                    </div>

                    <div
                        id="totalCount"
                        class="stat-number"
                    >
                        0
                    </div>

                </div>

            </div>

        </section>



        <!-- CONTENT -->

        <div class="content-grid">


            <!-- BOOKINGS -->

            <section
                class="panel"
                id="bookingsPanel"
            >

                <div class="panel-header">

                    <div class="panel-title">

                        <i class="fa-solid fa-calendar-check"></i>

                        مواعيد المرضى

                    </div>

                    <small
                        id="lastUpdate"
                        style="
                            color:#8a96a3;
                            font-size:10px;
                        "
                    >
                        —
                    </small>

                </div>


                <div class="filters">

                    <button
                        class="filter-btn active"
                        data-filter="all"
                        onclick="setFilter('all', this)"
                    >
                        الكل
                    </button>

                    <button
                        class="filter-btn"
                        data-filter="pending"
                        onclick="setFilter('pending', this)"
                    >
                        جديدة
                    </button>

                    <button
                        class="filter-btn"
                        data-filter="accepted"
                        onclick="setFilter('accepted', this)"
                    >
                        مقبولة
                    </button>

                    <button
                        class="filter-btn"
                        data-filter="rejected"
                        onclick="setFilter('rejected', this)"
                    >
                        مرفوضة
                    </button>

                    <button
                        class="filter-btn"
                        data-filter="completed"
                        onclick="setFilter('completed', this)"
                    >
                        مكتملة
                    </button>

                </div>


                <div id="bookingsList">

                    <div class="loading">

                        <i class="fa-solid fa-spinner"></i>

                        <p style="margin-top:10px;">
                            جاري تحميل المواعيد...
                        </p>

                    </div>

                </div>

            </section>



            <!-- SIDE -->

            <aside class="side-column">


                <!-- PROFILE -->

                <div class="side-card profile">

                    <div class="profile-avatar">

                        <i class="fa-solid fa-user-doctor"></i>

                    </div>

                    <h2 id="profileName">
                        الطبيب
                    </h2>

                    <div
                        id="profileSpecialty"
                        class="profile-specialty"
                    >
                        —
                    </div>

                    <div
                        id="profileRating"
                        class="profile-rating"
                    >
                        ⭐ 0.0
                    </div>

                </div>



                <!-- CLINIC -->

                <div class="side-card">

                    <div class="side-title">

                        <i class="fa-solid fa-hospital"></i>

                        معلومات العيادة

                    </div>


                    <div class="side-row">

                        <span>
                            العيادة
                        </span>

                        <strong id="clinicName">
                            —
                        </strong>

                    </div>


                    <div class="side-row">

                        <span>
                            الخبرة
                        </span>

                        <strong id="experience">
                            —
                        </strong>

                    </div>


                    <div class="side-row">

                        <span>
                            الهاتف
                        </span>

                        <strong id="doctorPhone">
                            —
                        </strong>

                    </div>

                </div>



                <!-- QUICK ACTIONS -->

                <div class="side-card">

                    <div class="side-title">

                        <i class="fa-solid fa-bolt"></i>

                        اختصارات

                    </div>


                    <button
                        class="action-btn complete-btn"
                        style="
                            width:100%;
                            margin-bottom:9px;
                        "
                        onclick="scrollToPending()"
                    >

                        <i class="fa-solid fa-calendar-day"></i>

                        المواعيد الجديدة

                    </button>


                    <button
                        class="action-btn whatsapp-btn"
                        style="
                            width:100%;
                            margin-bottom:9px;
                        "
                        onclick="contactLastPatient()"
                    >

                        <i class="fa-brands fa-whatsapp"></i>

                        آخر مريض

                    </button>


                    <button
                        class="logout-btn"
                        onclick="logout()"
                    >

                        <i class="fa-solid fa-right-from-bracket"></i>

                        تسجيل الخروج

                    </button>

                </div>

            </aside>

        </div>

    </main>

</section>



<!-- TOAST -->

<div id="toast">

    <i class="fa-solid fa-circle-check"></i>

    <span id="toastText">
        تم
    </span>

</div>



<script>

    /* =====================================================
       VARIABLES
    ===================================================== */

    let currentDoctor = null;

    let allBookings = [];

    let currentFilter = "all";

    let pollingTimer = null;

    let previousPending = 0;


    /* =====================================================
       ELEMENTS
    ===================================================== */

    const loginPage =
        document.getElementById("loginPage");

    const dashboard =
        document.getElementById("dashboard");


    /* =====================================================
       LOGIN
    ===================================================== */

    document
        .getElementById("loginForm")
        .addEventListener(
            "submit",
            async function(event) {

                event.preventDefault();

                const id =
                    document
                        .getElementById("doctorId")
                        .value;

                const password =
                    document
                        .getElementById("doctorPassword")
                        .value;

                const error =
                    document
                        .getElementById("loginError");

                error.style.display = "none";


                try {

                    const response =
                        await fetch(
                            "/api/doctors/login",
                            {
                                method: "POST",

                                headers: {
                                    "Content-Type":
                                        "application/json"
                                },

                                body:
                                    JSON.stringify({
                                        id:
                                            Number(id),
                                        password
                                    })
                            }
                        );


                    const data =
                        await response.json();


                    if (
                        !response.ok ||
                        !data.success
                    ) {

                        throw new Error(
                            data.message ||
                            "بيانات الدخول غير صحيحة"
                        );

                    }


                    currentDoctor =
                        data.doctor;


                    localStorage.setItem(
                        "tabibkDoctor",
                        JSON.stringify(
                            currentDoctor
                        )
                    );


                    showDashboard();

                }


                catch(error) {


                    /*
                     * تسجيل دخول تجريبي
                     */

                    if (
                        Number(id) === 1 &&
                        password === "123456"
                    ) {

                        currentDoctor = {

                            id: 1,

                            name:
                                "د. أحمد بن علي",

                            specialty:
                                "طب عام",

                            phone:
                                "0550000001",

                            clinic:
                                "عيادة الشفاء",

                            experience:
                                "12 سنة خبرة",

                            rating:
                                4.9

                        };


                        localStorage.setItem(
                            "tabibkDoctor",
                            JSON.stringify(
                                currentDoctor
                            )
                        );


                        showDashboard();


                        showToast(
                            "تم الدخول بنجاح 👨‍⚕️",
                            "success"
                        );


                        return;

                    }


                    error.textContent =
                        error.message;

                    error.style.display =
                        "block";

                }

            }
        );


    /* =====================================================
       SHOW DASHBOARD
    ===================================================== */

    function showDashboard() {

        loginPage.style.display =
            "none";

        dashboard.style.display =
            "block";


        updateDoctorUI();

        loadBookings();


        if (pollingTimer) {

            clearInterval(
                pollingTimer
            );

        }


        pollingTimer =
            setInterval(
                loadBookings,
                8000
            );

    }


    /* =====================================================
       DOCTOR UI
    ===================================================== */

    function updateDoctorUI() {

        if (!currentDoctor)
            return;


        document
            .getElementById("welcomeName")
            .textContent =
            `مرحباً ${currentDoctor.name} 👨‍⚕️`;


        document
            .getElementById("profileName")
            .textContent =
            currentDoctor.name;


        document
            .getElementById("profileSpecialty")
            .textContent =
            currentDoctor.specialty ||
            "طبيب";


        document
            .getElementById("profileRating")
            .textContent =
            `⭐ ${currentDoctor.rating || 0}`;


        document
            .getElementById("clinicName")
            .textContent =
            currentDoctor.clinic ||
            "—";


        document
            .getElementById("experience")
            .textContent =
            currentDoctor.experience ||
            "—";


        document
            .getElementById("doctorPhone")
            .textContent =
            currentDoctor.phone ||
            "—";

    }


    /* =====================================================
       LOAD BOOKINGS
    ===================================================== */

    async function loadBookings() {

        if (!currentDoctor)
            return;


        try {

            const response =
                await fetch(
                    "/api/bookings"
                );


            const data =
                await response.json();


            if (!data.success)
                throw new Error(
                    "تعذر تحميل المواعيد"
                );


            allBookings =
                data.bookings.filter(
                    booking =>
                        Number(
                            booking.doctorId
                        ) ===
                        Number(
                            currentDoctor.id
                        )
                );


            updateStats();

            renderBookings();


            document
                .getElementById("lastUpdate")
                .textContent =
                "آخر تحديث " +
                new Date()
                    .toLocaleTimeString(
                        "ar-DZ",
                        {
                            hour: "2-digit",
                            minute: "2-digit"
                        }
                    );

        }


        catch(error) {

            console.error(error);


            document
                .getElementById("bookingsList")
                .innerHTML = `

                    <div class="empty">

                        <i class="fa-solid fa-cloud-arrow-down"></i>

                        <h3>
                            تعذر الاتصال بالخادم
                        </h3>

                        <p>
                            تأكد أن TABIBK Server يعمل.
                        </p>

                    </div>

                `;

        }

    }


    /* =====================================================
       STATS
    ===================================================== */

    function updateStats() {

        const pending =
            allBookings.filter(
                b =>
                    b.status ===
                    "pending"
            ).length;


        const accepted =
            allBookings.filter(
                b =>
                    b.status ===
                    "accepted"
            ).length;


        const rejected =
            allBookings.filter(
                b =>
                    b.status ===
                    "rejected"
            ).length;


        const total =
            allBookings.length;


        document
            .getElementById("pendingCount")
            .textContent =
            pending;


        document
            .getElementById("acceptedCount")
            .textContent =
            accepted;


        document
            .getElementById("rejectedCount")
            .textContent =
            rejected;


        document
            .getElementById("totalCount")
            .textContent =
            total;


        const dot =
            document
                .getElementById(
                    "notificationDot"
                );


        if (pending > 0) {

            dot.style.display =
                "block";

        }

        else {

            dot.style.display =
                "none";

        }


        if (
            previousPending > 0 &&
            pending > previousPending
        ) {

            playNotificationSound();

            showToast(
                "🔔 لديك موعد جديد!",
                "success"
            );

        }


        previousPending =
            pending;

    }


    /* =====================================================
       FILTER
    ===================================================== */

    function setFilter(
        filter,
        button
    ) {

        currentFilter =
            filter;


        document
            .querySelectorAll(
                ".filter-btn"
            )
            .forEach(
                btn =>
                    btn.classList.remove(
                        "active"
                    )
            );


        button.classList.add(
            "active"
        );


        renderBookings();

    }


    /* =====================================================
       RENDER BOOKINGS
    ===================================================== */

    function renderBookings() {

        const container =
            document.getElementById(
                "bookingsList"
            );


        let bookings =
            [...allBookings];


        if (
            currentFilter !==
            "all"
        ) {

            bookings =
                bookings.filter(
                    b =>
                        b.status ===
                        currentFilter
                );

        }


        bookings.sort(
            (a, b) =>
                new Date(
                    b.createdAt || 0
                ) -
                new Date(
                    a.createdAt || 0
                )
        );


        if (!bookings.length) {

            container.innerHTML = `

                <div class="empty">

                    <i class="fa-regular fa-calendar-xmark"></i>

                    <h3>
                        لا توجد مواعيد
                    </h3>

                    <p>
                        لا توجد حجوزات ضمن هذا التصنيف حالياً.
                    </p>

                </div>

            `;

            return;

        }


        container.innerHTML =
            bookings
                .map(
                    booking =>
                        createBookingCard(
                            booking
                        )
                )
                .join("");

    }


    /* =====================================================
       BOOKING CARD
    ===================================================== */

    function createBookingCard(
        booking
    ) {

        const statusText = {

            pending:
                "قيد الانتظار",

            accepted:
                "مقبول",

            rejected:
                "مرفوض",

            completed:
                "مكتمل",

            cancelled:
                "ملغى"

        }[
            booking.status
        ] ||
        booking.status;


        const safeName =
            escapeHTML(
                booking.patientName
            );


        const safePhone =
            escapeHTML(
                booking.patientPhone
            );


        const safeNotes =
            escapeHTML(
                booking.notes || ""
            );


        let actions = "";


        if (
            booking.status ===
            "pending"
        ) {

            actions = `

                <button
                    class="action-btn accept-btn"
                    onclick="updateBooking(
                        '${booking.id}',
                        'accept'
                    )"
                >

                    <i class="fa-solid fa-check"></i>

                    قبول الموعد

                </button>


                <button
                    class="action-btn reject-btn"
                    onclick="updateBooking(
                        '${booking.id}',
                        'reject'
                    )"
                >

                    <i class="fa-solid fa-xmark"></i>

                    رفض

                </button>

            `;

        }


        else if (
            booking.status ===
            "accepted"
        ) {

            actions = `

                <button
                    class="action-btn complete-btn"
                    onclick="updateBooking(
                        '${booking.id}',
                        'complete'
                    )"
                >

                    <i class="fa-solid fa-check-double"></i>

                    إنهاء الموعد

                </button>

            `;

        }


        if (
            booking.patientPhone
        ) {

            actions += `

                <button
                    class="action-btn whatsapp-btn"
                    onclick="contactPatient(
                        '${booking.patientPhone}',
                        '${escapeAttribute(
                            booking.patientName
                        )}'
                    )"
                >

                    <i class="fa-brands fa-whatsapp"></i>

                    واتساب

                </button>

            `;

        }


        return `

            <article
                class="booking-card"
                data-booking-id="${booking.id}"
            >

                <div class="booking-top">

                    <div class="patient">

                        <div class="patient-avatar">

                            <i class="fa-solid fa-user"></i>

                        </div>

                        <div>

                            <div class="patient-name">
                                ${safeName}
                            </div>

                            <div class="booking-id">
                                ${booking.id}
                            </div>

                        </div>

                    </div>


                    <span
                        class="status ${booking.status}"
                    >
                        ${statusText}
                    </span>

                </div>


                <div class="booking-info">


                    <div class="info-item">

                        <span class="info-label">
                            التاريخ
                        </span>

                        <span class="info-value">

                            <i class="fa-regular fa-calendar"></i>

                            ${escapeHTML(
                                booking.date
                            )}

                        </span>

                    </div>


                    <div class="info-item">

                        <span class="info-label">
                            الوقت
                        </span>

                        <span class="info-value">

                            <i class="fa-regular fa-clock"></i>

                            ${escapeHTML(
                                booking.time
                            )}

                        </span>

                    </div>


                    <div class="info-item">

                        <span class="info-label">
                            نوع الموعد
                        </span>

                        <span class="info-value">

                            <i class="fa-solid fa-stethoscope"></i>

                            ${escapeHTML(
                                booking.type ||
                                "فحص واستشارة"
                            )}

                        </span>

                    </div>


                    <div class="info-item">

                        <span class="info-label">
                            الهاتف
                        </span>

                        <span class="info-value">

                            <i class="fa-solid fa-phone"></i>

                            ${safePhone}

                        </span>

                    </div>

                </div>


                ${
                    safeNotes
                    ?
                    `
                    <div class="notes">

                        <strong>

                            <i class="fa-solid fa-note-sticky"></i>

                            ملاحظات:

                        </strong>

                        ${safeNotes}

                    </div>
                    `
                    :
                    ""
                }


                <div class="booking-actions">

                    ${actions}

                </div>

            </article>

        `;

    }


    /* =====================================================
       UPDATE BOOKING
    ===================================================== */

    async function updateBooking(
        id,
        action
    ) {

        let endpoint = "";

        let successMessage = "";


        if (
            action ===
            "accept"
        ) {

            endpoint =
                `/api/bookings/${id}/accept`;

            successMessage =
                "تم قبول الموعد ✅";

        }


        else if (
            action ===
            "reject"
        ) {

            endpoint =
                `/api/bookings/${id}/reject`;

            successMessage =
                "تم رفض الموعد";

        }


        else if (
            action ===
            "complete"
        ) {

            endpoint =
                `/api/bookings/${id}/complete`;

            successMessage =
                "تم إنهاء الموعد بنجاح ✅";

        }


        if (!endpoint)
            return;


        try {

            const response =
                await fetch(
                    endpoint,
                    {
                        method: "POST",

                        headers: {
                            "Content-Type":
                                "application/json"
                        }
                    }
                );


            const data =
                await response.json();


            if (
                !response.ok ||
                !data.success
            ) {

                throw new Error(
                    data.message ||
                    "تعذر تحديث الموعد"
                );

            }


            showToast(
                successMessage,
                "success"
            );


            playNotificationSound();


            await loadBookings();

        }


        catch(error) {

            showToast(
                error.message,
                "error"
            );

        }

    }


    /* =====================================================
       WHATSAPP
    ===================================================== */

    function contactPatient(
        phone,
        name
    ) {

        let clean =
            String(phone)
                .replace(
                    /[^0-9]/g,
                    ""
                );


        if (
            clean.startsWith("0")
        ) {

            clean =
                "213" +
                clean.substring(1);

        }


        const message =
            encodeURIComponent(
                `السلام عليكم ${name}، معك طبيبك عبر تطبيق TABIBK 🩺`
            );


        window.open(
            `https://wa.me/${clean}?text=${message}`,
            "_blank"
        );

    }


    /* =====================================================
       LAST PATIENT
    ===================================================== */

    function contactLastPatient() {

        if (!allBookings.length) {

            showToast(
                "لا يوجد مرضى حالياً",
                "error"
            );

            return;

        }


        const booking =
            allBookings[0];


        contactPatient(
            booking.patientPhone,
            booking.patientName
        );

    }


    /* =====================================================
       REFRESH
    ===================================================== */

    function refreshBookings() {

        const button =
            document.querySelector(
                ".header-actions .icon-btn"
            );


        button
            .querySelector("i")
            .classList.add(
                "fa-spin"
            );


        loadBookings()
            .finally(
                () => {

                    setTimeout(
                        () => {

                            button
                                .querySelector("i")
                                .classList.remove(
                                    "fa-spin"
                                );

                        },
                        500
                    );

                }
            );

    }


    /* =====================================================
       SCROLL
    ===================================================== */

    function scrollToPending() {

        const panel =
            document.getElementById(
                "bookingsPanel"
            );


        panel.scrollIntoView({
            behavior: "smooth",
            block: "start"
        });


        const pendingButton =
            document.querySelector(
                '[data-filter="pending"]'
            );


        if (pendingButton) {

            setFilter(
                "pending",
                pendingButton
            );

        }

    }


    /* =====================================================
       LOGOUT
    ===================================================== */

    function logout() {

        if (
            !confirm(
                "هل تريد تسجيل الخروج؟"
            )
        )
            return;


        localStorage.removeItem(
            "tabibkDoctor"
        );


        currentDoctor = null;


        if (pollingTimer) {

            clearInterval(
                pollingTimer
            );

        }


        dashboard.style.display =
            "none";


        loginPage.style.display =
            "flex";


        document
            .getElementById(
                "doctorPassword"
            )
            .value = "";

    }


    /* =====================================================
       TOAST
    ===================================================== */

    let toastTimer;


    function showToast(
        message,
        type = "success"
    ) {

        const toast =
            document.getElementById(
                "toast"
            );


        const text =
            document.getElementById(
                "toastText"
            );


        text.textContent =
            message;


        toast.className =
            type + " show";


        clearTimeout(
            toastTimer
        );


        toastTimer =
            setTimeout(
                () => {

                    toast.classList.remove(
                        "show"
                    );

                },
                3000
            );

    }


    /* =====================================================
       SOUND
    ===================================================== */

    function playNotificationSound() {

        try {

            const AudioContext =
                window.AudioContext ||
                window.webkitAudioContext;


            if (!AudioContext)
                return;


            const audio =
                new AudioContext();


            const oscillator =
                audio.createOscillator();


            const gain =
                audio.createGain();


            oscillator.type =
                "sine";


            oscillator.frequency.value =
                880;


            gain.gain.value =
                .08;


            oscillator.connect(
                gain
            );


            gain.connect(
                audio.destination
            );


            oscillator.start();


            oscillator.stop(
                audio.currentTime +
                .15
            );

        }


        catch(error) {

            console.log(
                "Sound unavailable"
            );

        }

    }


    /* =====================================================
       SECURITY
    ===================================================== */

    function escapeHTML(
        value
    ) {

        return String(
            value ?? ""
        )
        .replace(
            /&/g,
            "&amp;"
        )
        .replace(
            /</g,
            "&lt;"
        )
        .replace(
            />/g,
            "&gt;"
        )
        .replace(
            /"/g,
            "&quot;"
        )
        .replace(
            /'/g,
            "&#039;"
        );

    }


    function escapeAttribute(
        value
    ) {

        return String(
            value ?? ""
        )
        .replace(
            /\\/g,
            "\\\\"
        )
        .replace(
            /'/g,
            "\\'"
        )
        .replace(
            /"/g,
            "&quot;"
        );

    }


    /* =====================================================
       AUTO LOGIN
    ===================================================== */

    window.addEventListener(
        "DOMContentLoaded",
        () => {

            const saved =
                localStorage.getItem(
                    "tabibkDoctor"
                );


            if (saved) {

                try {

                    currentDoctor =
                        JSON.parse(
                            saved
                        );

                    showDashboard();

                }

                catch(error) {

                    localStorage.removeItem(
                        "tabibkDoctor"
                    );

                }

            }

        }
    );

</script>

</body>

</html>
