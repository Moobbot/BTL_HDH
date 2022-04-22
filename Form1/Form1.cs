using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;



namespace Form1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            GetProcess();
        }
        /// <summary>
        /// lưu lại danh sách process - Tiến trình
        /// </summary>
        Process[] process;

        /// <summary>
        /// Lấy lên danh sách process và lưu lại
        /// Đồng thời show lên list view
        /// </summary>
        void GetProcess()
        {
            process = Process.GetProcesses();
            listView1.Items.Clear(); // Làm sạch trước khi thêm
            foreach (var item in process)
            {
                //ProcessName: Lấy tên của tiến trình
                ListViewItem newItem = new ListViewItem() { Text = item.ProcessName};

                //Responding: Nhận một giá trị cho biết liệu giao diện người dùng của quy trình có phản hồi hay không.
                //true nếu giao diện người dùng của quy trình liên quan đang phản hồi với hệ thống; ngược lại, false
                if (item.Responding == true)
                {
                    newItem.SubItems.Add(new ListViewItem.ListViewSubItem() { Text = item.Responding.ToString() });
                }
                else
                {
                    newItem.SubItems.Add(new ListViewItem.ListViewSubItem() { Text = "" });

                }

                //
                try
                {
                    PerformanceCounter counter = new PerformanceCounter("Process", "Private Bytes", item.ProcessName, true);
                    PerformanceCounter setCounter = new PerformanceCounter("Process", "Working Set", item.ProcessName, true);
                    PerformanceCounter poolNPCounter = new PerformanceCounter("Process", "Pool Nonpaged Bytes", item.ProcessName, true);
                    newItem.SubItems.Add(new ListViewItem.ListViewSubItem() { Text = ((setCounter.NextValue() / 1024f)).ToString() + " KB" });
                }
                catch (Exception ex)
                {
                    newItem.SubItems.Add(new ListViewItem.ListViewSubItem() { Text = "CPU" });
                }


                //Memory: Bộ nhớ ảo sử dụng
                //Nhận lượng bộ nhớ riêng, tính bằng byte, được phân bổ cho quá trình liên quan.
                double memory = ((int)item.PrivateMemorySize64) / (Math.Pow(1024, 2));
                newItem.SubItems.Add(new ListViewItem.ListViewSubItem() { Text = Math.Round(memory, 2) + " MB"});
                
                //Description: Mô tả ứng dụng
                ////MainWindowTitle Lấy chú thích của cửa sổ chính của quá trình.
                newItem.SubItems.Add(new ListViewItem.ListViewSubItem() { Text = item.MainWindowTitle.ToString() });

                listView1.Items.Add(newItem);
            }
            //List<Process> list = new List<Process>();
            //list.Sort();
            //process = list.ToArray();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            //if (process.Length!= Process.GetProcesses().Length)
            //{
                GetProcess();
            //}
        }

        /// <summary>
        /// Kết thúc tiến trình
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void endtaskToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(listView1.SelectedItems.Count>0)
            {
                int index = 0;
                foreach (var item in process)
                {
                    if(item.ProcessName == listView1.SelectedItems[0].Text)
                    {
                        index = process.ToList().IndexOf(item);
                        break;
                    }
                }    
                process[index].Kill();
            }    
            //Có một số app phải dùng quyền admin mới chạy được.
        }

        private void listView1_ColumnClick(object sender, ColumnClickEventArgs e)
        {
            listView1.ListViewItemSorter = new ListViewItemCompaper(e.Column);
            listView1.Sort();
        }
    }
}
