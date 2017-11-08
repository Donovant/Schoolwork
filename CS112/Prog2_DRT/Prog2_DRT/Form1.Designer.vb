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
        Me.GreenBox = New System.Windows.Forms.TextBox
        Me.YellowBox = New System.Windows.Forms.TextBox
        Me.RedBox = New System.Windows.Forms.TextBox
        Me.SuspendLayout()
        '
        'GreenBox
        '
        Me.GreenBox.BackColor = System.Drawing.SystemColors.InactiveCaptionText
        Me.GreenBox.Font = New System.Drawing.Font("Microsoft Sans Serif", 20.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.GreenBox.Location = New System.Drawing.Point(116, 187)
        Me.GreenBox.Name = "GreenBox"
        Me.GreenBox.Size = New System.Drawing.Size(36, 38)
        Me.GreenBox.TabIndex = 0
        '
        'YellowBox
        '
        Me.YellowBox.BackColor = System.Drawing.SystemColors.InactiveCaptionText
        Me.YellowBox.Font = New System.Drawing.Font("Microsoft Sans Serif", 20.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.YellowBox.Location = New System.Drawing.Point(116, 105)
        Me.YellowBox.Name = "YellowBox"
        Me.YellowBox.Size = New System.Drawing.Size(36, 38)
        Me.YellowBox.TabIndex = 1
        '
        'RedBox
        '
        Me.RedBox.BackColor = System.Drawing.SystemColors.InactiveCaptionText
        Me.RedBox.Font = New System.Drawing.Font("Microsoft Sans Serif", 20.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.RedBox.Location = New System.Drawing.Point(116, 22)
        Me.RedBox.Name = "RedBox"
        Me.RedBox.Size = New System.Drawing.Size(36, 38)
        Me.RedBox.TabIndex = 2
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(284, 262)
        Me.Controls.Add(Me.RedBox)
        Me.Controls.Add(Me.YellowBox)
        Me.Controls.Add(Me.GreenBox)
        Me.Name = "Form1"
        Me.Text = "Red Light, Green Light"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents GreenBox As System.Windows.Forms.TextBox
    Friend WithEvents YellowBox As System.Windows.Forms.TextBox
    Friend WithEvents RedBox As System.Windows.Forms.TextBox

End Class
