<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.ratesBtn = New System.Windows.Forms.Button
        Me.Label1 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.billBtn = New System.Windows.Forms.Button
        Me.equip = New System.Windows.Forms.TextBox
        Me.duration = New System.Windows.Forms.TextBox
        Me.table = New System.Windows.Forms.ListBox
        Me.receipt = New System.Windows.Forms.ListBox
        Me.SuspendLayout()
        '
        'ratesBtn
        '
        Me.ratesBtn.Location = New System.Drawing.Point(12, 18)
        Me.ratesBtn.Name = "ratesBtn"
        Me.ratesBtn.Size = New System.Drawing.Size(144, 62)
        Me.ratesBtn.TabIndex = 0
        Me.ratesBtn.Text = "Display Rental Rates"
        Me.ratesBtn.UseVisualStyleBackColor = True
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(12, 114)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(128, 13)
        Me.Label1.TabIndex = 1
        Me.Label1.Text = "Select an item (1, 2, or 3):"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(9, 141)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(128, 13)
        Me.Label2.TabIndex = 2
        Me.Label2.Text = "Select a duration (H or F):"
        '
        'billBtn
        '
        Me.billBtn.Location = New System.Drawing.Point(15, 168)
        Me.billBtn.Name = "billBtn"
        Me.billBtn.Size = New System.Drawing.Size(141, 38)
        Me.billBtn.TabIndex = 3
        Me.billBtn.Text = "Display Customer Bill"
        Me.billBtn.UseVisualStyleBackColor = True
        '
        'equip
        '
        Me.equip.Location = New System.Drawing.Point(139, 116)
        Me.equip.Name = "equip"
        Me.equip.Size = New System.Drawing.Size(28, 20)
        Me.equip.TabIndex = 6
        '
        'duration
        '
        Me.duration.Location = New System.Drawing.Point(137, 142)
        Me.duration.Name = "duration"
        Me.duration.Size = New System.Drawing.Size(30, 20)
        Me.duration.TabIndex = 7
        '
        'table
        '
        Me.table.Font = New System.Drawing.Font("Courier New", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.table.FormattingEnabled = True
        Me.table.ItemHeight = 18
        Me.table.Location = New System.Drawing.Point(173, 18)
        Me.table.Name = "table"
        Me.table.Size = New System.Drawing.Size(477, 76)
        Me.table.TabIndex = 8
        '
        'receipt
        '
        Me.receipt.Font = New System.Drawing.Font("Courier New", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.receipt.FormattingEnabled = True
        Me.receipt.ItemHeight = 18
        Me.receipt.Location = New System.Drawing.Point(173, 116)
        Me.receipt.Name = "receipt"
        Me.receipt.Size = New System.Drawing.Size(477, 112)
        Me.receipt.TabIndex = 9
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(664, 237)
        Me.Controls.Add(Me.receipt)
        Me.Controls.Add(Me.table)
        Me.Controls.Add(Me.duration)
        Me.Controls.Add(Me.equip)
        Me.Controls.Add(Me.billBtn)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.ratesBtn)
        Me.Name = "Form1"
        Me.Text = "Welcome to Eddie's Equipment Rental"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents ratesBtn As System.Windows.Forms.Button
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents billBtn As System.Windows.Forms.Button
    Friend WithEvents equip As System.Windows.Forms.TextBox
    Friend WithEvents duration As System.Windows.Forms.TextBox
    Friend WithEvents table As System.Windows.Forms.ListBox
    Friend WithEvents receipt As System.Windows.Forms.ListBox

End Class
