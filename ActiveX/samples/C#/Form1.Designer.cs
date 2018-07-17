namespace Biokey01
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
                //axZKFPEngX1.FreeFPCacheDB(fpcHandle);
            }
            //showpicture.Stop();
            //showpicture.Close();
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.txtb2 = new System.Windows.Forms.TextBox();
            this.statusBar1 = new System.Windows.Forms.StatusBar();
            this.statusbar0 = new System.Windows.Forms.StatusBarPanel();
            this.statusBarPanel1 = new System.Windows.Forms.StatusBarPanel();
            this.statusBarPanel2 = new System.Windows.Forms.StatusBarPanel();
            this.statusBarPanel3 = new System.Windows.Forms.StatusBarPanel();
            this.chkFakeFunOn = new System.Windows.Forms.CheckBox();
            this.btnCloseSensor = new System.Windows.Forms.Button();
            this.txtb5 = new System.Windows.Forms.TextBox();
            this.txtb1 = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.btnInitialSensor = new System.Windows.Forms.Button();
            this.btnbrowse = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.btnBeep = new System.Windows.Forms.Button();
            this.btnGreen = new System.Windows.Forms.Button();
            this.btnRed = new System.Windows.Forms.Button();
            this.btnIdentifyByImage = new System.Windows.Forms.Button();
            this.btnRegByImage = new System.Windows.Forms.Button();
            this.btnVerify = new System.Windows.Forms.Button();
            this.btnReg = new System.Windows.Forms.Button();
            this.axZKFPEngX1 = new AxZKFPEngXControl.AxZKFPEngX();
            this.rdb10 = new System.Windows.Forms.RadioButton();
            this.rdb9 = new System.Windows.Forms.RadioButton();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.btnIdentify = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.statusbar0)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.statusBarPanel1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.statusBarPanel2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.statusBarPanel3)).BeginInit();
            this.groupBox4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.axZKFPEngX1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // txtb2
            // 
            this.txtb2.Location = new System.Drawing.Point(628, 8);
            this.txtb2.Name = "txtb2";
            this.txtb2.ReadOnly = true;
            this.txtb2.Size = new System.Drawing.Size(68, 21);
            this.txtb2.TabIndex = 3;
            // 
            // statusBar1
            // 
            this.statusBar1.Location = new System.Drawing.Point(0, 371);
            this.statusBar1.Name = "statusBar1";
            this.statusBar1.Panels.AddRange(new System.Windows.Forms.StatusBarPanel[] {
            this.statusbar0});
            this.statusBar1.ShowPanels = true;
            this.statusBar1.Size = new System.Drawing.Size(714, 24);
            this.statusBar1.TabIndex = 14;
            // 
            // statusbar0
            // 
            this.statusbar0.Name = "statusbar0";
            this.statusbar0.Text = "Status:";
            this.statusbar0.Width = 770;
            // 
            // statusBarPanel1
            // 
            this.statusBarPanel1.Alignment = System.Windows.Forms.HorizontalAlignment.Center;
            this.statusBarPanel1.Name = "statusBarPanel1";
            this.statusBarPanel1.Text = "Status:";
            this.statusBarPanel1.Width = 80;
            // 
            // statusBarPanel2
            // 
            this.statusBarPanel2.Name = "statusBarPanel2";
            this.statusBarPanel2.Width = 200;
            // 
            // statusBarPanel3
            // 
            this.statusBarPanel3.Name = "statusBarPanel3";
            // 
            // chkFakeFunOn
            // 
            this.chkFakeFunOn.AutoSize = true;
            this.chkFakeFunOn.Location = new System.Drawing.Point(569, 218);
            this.chkFakeFunOn.Name = "chkFakeFunOn";
            this.chkFakeFunOn.Size = new System.Drawing.Size(78, 16);
            this.chkFakeFunOn.TabIndex = 10;
            this.chkFakeFunOn.Text = "FakeFunOn";
            this.chkFakeFunOn.UseVisualStyleBackColor = true;
            // 
            // btnCloseSensor
            // 
            this.btnCloseSensor.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnCloseSensor.Enabled = false;
            this.btnCloseSensor.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnCloseSensor.Location = new System.Drawing.Point(569, 132);
            this.btnCloseSensor.Name = "btnCloseSensor";
            this.btnCloseSensor.Size = new System.Drawing.Size(118, 23);
            this.btnCloseSensor.TabIndex = 9;
            this.btnCloseSensor.Text = "Disonnect Sensor";
            this.btnCloseSensor.UseVisualStyleBackColor = true;
            this.btnCloseSensor.Click += new System.EventHandler(this.btnCloseSensor_Click);
            // 
            // txtb5
            // 
            this.txtb5.Location = new System.Drawing.Point(455, 49);
            this.txtb5.Name = "txtb5";
            this.txtb5.ReadOnly = true;
            this.txtb5.Size = new System.Drawing.Size(241, 21);
            this.txtb5.TabIndex = 8;
            // 
            // txtb1
            // 
            this.txtb1.Location = new System.Drawing.Point(450, 8);
            this.txtb1.Name = "txtb1";
            this.txtb1.ReadOnly = true;
            this.txtb1.Size = new System.Drawing.Size(52, 21);
            this.txtb1.TabIndex = 4;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(367, 52);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(83, 12);
            this.label6.TabIndex = 3;
            this.label6.Text = "Serial Number";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(569, 12);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(47, 12);
            this.label5.TabIndex = 2;
            this.label5.Text = "Current";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(367, 12);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(77, 12);
            this.label4.TabIndex = 1;
            this.label4.Text = "Sensor Count";
            // 
            // btnInitialSensor
            // 
            this.btnInitialSensor.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnInitialSensor.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnInitialSensor.Location = new System.Drawing.Point(367, 132);
            this.btnInitialSensor.Name = "btnInitialSensor";
            this.btnInitialSensor.Size = new System.Drawing.Size(118, 20);
            this.btnInitialSensor.TabIndex = 0;
            this.btnInitialSensor.Text = "Connect Sensor";
            this.btnInitialSensor.UseVisualStyleBackColor = true;
            this.btnInitialSensor.Click += new System.EventHandler(this.btnInitialSensor_Click);
            // 
            // btnbrowse
            // 
            this.btnbrowse.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnbrowse.Location = new System.Drawing.Point(367, 172);
            this.btnbrowse.Name = "btnbrowse";
            this.btnbrowse.Size = new System.Drawing.Size(118, 21);
            this.btnbrowse.TabIndex = 14;
            this.btnbrowse.Text = "SaveImage";
            this.btnbrowse.UseVisualStyleBackColor = true;
            this.btnbrowse.Click += new System.EventHandler(this.btnbrowse_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.radioButton2);
            this.groupBox4.Controls.Add(this.radioButton1);
            this.groupBox4.Location = new System.Drawing.Point(569, 166);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(118, 36);
            this.groupBox4.TabIndex = 12;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Format";
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(60, 14);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(41, 16);
            this.radioButton2.TabIndex = 1;
            this.radioButton2.Text = "JPG";
            this.radioButton2.UseVisualStyleBackColor = true;
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Checked = true;
            this.radioButton1.Location = new System.Drawing.Point(6, 14);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(41, 16);
            this.radioButton1.TabIndex = 1;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "BMP";
            this.radioButton1.UseVisualStyleBackColor = true;
            // 
            // btnBeep
            // 
            this.btnBeep.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnBeep.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnBeep.Location = new System.Drawing.Point(617, 332);
            this.btnBeep.Name = "btnBeep";
            this.btnBeep.Size = new System.Drawing.Size(72, 23);
            this.btnBeep.TabIndex = 14;
            this.btnBeep.Text = "Beep";
            this.btnBeep.UseVisualStyleBackColor = true;
            this.btnBeep.Click += new System.EventHandler(this.btnBeep_Click);
            // 
            // btnGreen
            // 
            this.btnGreen.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnGreen.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnGreen.Location = new System.Drawing.Point(490, 332);
            this.btnGreen.Name = "btnGreen";
            this.btnGreen.Size = new System.Drawing.Size(72, 23);
            this.btnGreen.TabIndex = 13;
            this.btnGreen.Text = "Green";
            this.btnGreen.UseVisualStyleBackColor = true;
            this.btnGreen.Click += new System.EventHandler(this.btnGreen_Click);
            // 
            // btnRed
            // 
            this.btnRed.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnRed.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnRed.Location = new System.Drawing.Point(367, 332);
            this.btnRed.Name = "btnRed";
            this.btnRed.Size = new System.Drawing.Size(72, 23);
            this.btnRed.TabIndex = 12;
            this.btnRed.Text = "Red";
            this.btnRed.UseVisualStyleBackColor = true;
            this.btnRed.Click += new System.EventHandler(this.btnRed_Click);
            // 
            // btnIdentifyByImage
            // 
            this.btnIdentifyByImage.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnIdentifyByImage.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnIdentifyByImage.Location = new System.Drawing.Point(571, 292);
            this.btnIdentifyByImage.Name = "btnIdentifyByImage";
            this.btnIdentifyByImage.Size = new System.Drawing.Size(118, 23);
            this.btnIdentifyByImage.TabIndex = 11;
            this.btnIdentifyByImage.Text = "Identify by image";
            this.btnIdentifyByImage.UseVisualStyleBackColor = true;
            this.btnIdentifyByImage.Click += new System.EventHandler(this.btnIdentifyByImage_Click);
            // 
            // btnRegByImage
            // 
            this.btnRegByImage.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnRegByImage.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnRegByImage.Location = new System.Drawing.Point(367, 292);
            this.btnRegByImage.Name = "btnRegByImage";
            this.btnRegByImage.Size = new System.Drawing.Size(118, 23);
            this.btnRegByImage.TabIndex = 10;
            this.btnRegByImage.Text = "Register by image";
            this.btnRegByImage.UseVisualStyleBackColor = true;
            this.btnRegByImage.Click += new System.EventHandler(this.btnRegByImage_Click);
            // 
            // btnVerify
            // 
            this.btnVerify.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnVerify.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnVerify.Location = new System.Drawing.Point(367, 252);
            this.btnVerify.Name = "btnVerify";
            this.btnVerify.Size = new System.Drawing.Size(118, 23);
            this.btnVerify.TabIndex = 4;
            this.btnVerify.Text = "Verify 1 : 1";
            this.btnVerify.UseVisualStyleBackColor = true;
            this.btnVerify.Click += new System.EventHandler(this.btnVerify_Click);
            // 
            // btnReg
            // 
            this.btnReg.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnReg.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnReg.Location = new System.Drawing.Point(367, 212);
            this.btnReg.Name = "btnReg";
            this.btnReg.Size = new System.Drawing.Size(118, 23);
            this.btnReg.TabIndex = 0;
            this.btnReg.Text = "Register";
            this.btnReg.UseVisualStyleBackColor = true;
            this.btnReg.Click += new System.EventHandler(this.btnReg_Click);
            // 
            // axZKFPEngX1
            // 
            this.axZKFPEngX1.Enabled = true;
            this.axZKFPEngX1.Location = new System.Drawing.Point(458, 166);
            this.axZKFPEngX1.Name = "axZKFPEngX1";
            this.axZKFPEngX1.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axZKFPEngX1.OcxState")));
            this.axZKFPEngX1.Size = new System.Drawing.Size(24, 24);
            this.axZKFPEngX1.TabIndex = 3;
            this.axZKFPEngX1.OnFeatureInfo += new AxZKFPEngXControl.IZKFPEngXEvents_OnFeatureInfoEventHandler(this.axZKFPEngX1_OnFeatureInfo);
            this.axZKFPEngX1.OnImageReceived += new AxZKFPEngXControl.IZKFPEngXEvents_OnImageReceivedEventHandler(this.axZKFPEngX1_OnImageReceived);
            this.axZKFPEngX1.OnEnroll += new AxZKFPEngXControl.IZKFPEngXEvents_OnEnrollEventHandler(this.axZKFPEngX1_OnEnroll);
            this.axZKFPEngX1.OnCapture += new AxZKFPEngXControl.IZKFPEngXEvents_OnCaptureEventHandler(this.axZKFPEngX1_OnCapture);
            // 
            // rdb10
            // 
            this.rdb10.AutoSize = true;
            this.rdb10.Checked = true;
            this.rdb10.Location = new System.Drawing.Point(569, 92);
            this.rdb10.Name = "rdb10";
            this.rdb10.Size = new System.Drawing.Size(101, 16);
            this.rdb10.TabIndex = 1;
            this.rdb10.TabStop = true;
            this.rdb10.Text = "ZKFinger 10.0";
            this.rdb10.UseVisualStyleBackColor = true;
            // 
            // rdb9
            // 
            this.rdb9.AutoSize = true;
            this.rdb9.Location = new System.Drawing.Point(367, 92);
            this.rdb9.Name = "rdb9";
            this.rdb9.Size = new System.Drawing.Size(95, 16);
            this.rdb9.TabIndex = 0;
            this.rdb9.Text = "ZKFinger 9.0";
            this.rdb9.UseVisualStyleBackColor = true;
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // btnIdentify
            // 
            this.btnIdentify.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnIdentify.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnIdentify.Location = new System.Drawing.Point(569, 252);
            this.btnIdentify.Name = "btnIdentify";
            this.btnIdentify.Size = new System.Drawing.Size(118, 23);
            this.btnIdentify.TabIndex = 18;
            this.btnIdentify.Text = "Identify 1 : N";
            this.btnIdentify.UseVisualStyleBackColor = true;
            this.btnIdentify.Click += new System.EventHandler(this.btnIdentify_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.pictureBox1.Location = new System.Drawing.Point(12, 12);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(274, 343);
            this.pictureBox1.TabIndex = 11;
            this.pictureBox1.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(714, 395);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.axZKFPEngX1);
            this.Controls.Add(this.btnBeep);
            this.Controls.Add(this.btnIdentify);
            this.Controls.Add(this.btnGreen);
            this.Controls.Add(this.btnVerify);
            this.Controls.Add(this.btnRed);
            this.Controls.Add(this.chkFakeFunOn);
            this.Controls.Add(this.btnIdentifyByImage);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.btnRegByImage);
            this.Controls.Add(this.btnbrowse);
            this.Controls.Add(this.btnCloseSensor);
            this.Controls.Add(this.rdb10);
            this.Controls.Add(this.btnInitialSensor);
            this.Controls.Add(this.rdb9);
            this.Controls.Add(this.btnReg);
            this.Controls.Add(this.txtb5);
            this.Controls.Add(this.txtb1);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.statusBar1);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.txtb2);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Demo";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.statusbar0)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.statusBarPanel1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.statusBarPanel2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.statusBarPanel3)).EndInit();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.axZKFPEngX1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtb2;
        private System.Windows.Forms.StatusBar statusBar1;
        internal System.Windows.Forms.StatusBarPanel statusBarPanel1;
        internal System.Windows.Forms.StatusBarPanel statusBarPanel2;
        internal System.Windows.Forms.StatusBarPanel statusBarPanel3;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button btnInitialSensor;
        private System.Windows.Forms.TextBox txtb5;
        private System.Windows.Forms.TextBox txtb1;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.Button btnCloseSensor;
        private System.Windows.Forms.StatusBarPanel sstatusbar0;
        private System.Windows.Forms.StatusBarPanel statusBarPanel4;
        private System.Windows.Forms.StatusBarPanel statusbar0;
        private System.Windows.Forms.Button btnbrowse;
        private System.Windows.Forms.Button btnReg;
        private System.Windows.Forms.Button btnVerify;
        private System.Windows.Forms.RadioButton rdb10;
        private System.Windows.Forms.RadioButton rdb9;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private AxZKFPEngXControl.AxZKFPEngX axZKFPEngX1;
        private System.Windows.Forms.CheckBox chkFakeFunOn;
        private System.Windows.Forms.Button btnBeep;
        private System.Windows.Forms.Button btnGreen;
        private System.Windows.Forms.Button btnRed;
        private System.Windows.Forms.Button btnIdentifyByImage;
        private System.Windows.Forms.Button btnRegByImage;
        private System.Windows.Forms.Button btnIdentify;
        private System.Windows.Forms.PictureBox pictureBox1;
    }
}

