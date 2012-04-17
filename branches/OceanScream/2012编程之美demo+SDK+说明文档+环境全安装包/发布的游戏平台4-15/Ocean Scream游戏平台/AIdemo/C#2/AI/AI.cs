using System;
using System.Collections.Generic;
using System.Text;
using MSTCOS.SDK;

namespace MSTCOS.SDK
{
    public class AI : AbstractAI
    {
        public AI(OSInterface Interface)
            : base(Interface)
        {
        }

        float[] xx = { -384, 384, 0, -384, 384 };
        float[] yy = { -384, -384, 0, 384, 384 };

        List<ResourceInfo> resources;
        List<ResourceInfo> myresources;

        List<ShipInfo> ships;
        List<ShipInfo> a;
        List<ShipInfo> b;

        Random random = new Random();
        float rangeSquared = 62500;

        private float dist(ShipInfo a, ShipInfo b)
        {
            return (a.PositionX - b.PositionX) * (a.PositionX - b.PositionX) + (a.PositionY - b.PositionY) * (a.PositionY - b.PositionY);
        }

        bool IsTargetInRange(ShipInfo a, ShipInfo b)
        {
            bool p = dist(a, b) < rangeSquared; //在射程范围内
            //bool q = Math.Acos(Vector2.Dot(new Vector2(a.PositionX, a.PositionY), new Vector2(b.PositionX, b.PositionY))) < MathHelper.PiOver4 / 2;
            return p;
        }

        bool IsIslandInRange(ShipInfo a)
        {
            for (int i = 0; i < 5; i++)
            {
                if (a.PositionX > xx[i] - 196 && a.PositionX < xx[i] + 196 && a.PositionY > yy[i] - 196 && a.PositionY < yy[i] + 196) return true;
            }
            return false;
        }

        public override void Iteration()
        {
            int i, j, jj, k, kk;
            float d, t;

            ships = Interface.Ship;
            resources = Interface.Resource;
            myresources = new List<ResourceInfo>();
            if (resources.Count > 0)
            {
                foreach (var r in resources)
                    if (r.Faction == Interface.Faction)
                        myresources.Add(r);
            }

            a = new List<ShipInfo>();
            b = new List<ShipInfo>();

            for (i = 0; i < ships.Count; i++)
                if (ships[i].Faction == Interface.Faction) a.Add(ships[i]);
                else b.Add(ships[i]);

            //for (i = 0; i < a.Count; i++) Console.Write(a[i].ID + ":" + a[i].PositionX + "," + a[i].PositionY + ";");
            //Console.WriteLine();

            //for (i = 0; i < b.Count; i++) Console.Write(b[i].ID + ":" + b[i].PositionX + "," + b[i].PositionY + ";");
            //Console.WriteLine();

            for (i = 0; i < a.Count; i++)
            {
                d = -1;
                jj = 0;
                for (j = 0; j < b.Count; j++)
                {
                    t = dist(a[i], b[j]);
                    if (t < d || d == -1)
                    {
                        d = t;
                        jj = j;
                    }
                }
                d = -1;
                kk = 0;
                for (k = 0; k < 5; k++)
                {
                    t = (a[i].PositionX - xx[k]) * (a[i].PositionX - xx[k]) + (a[i].PositionY - yy[k]) * (a[i].PositionY - yy[k]);
                    if (t < d || d == -1)
                    {
                        d = t;
                        kk = k;
                    }
                }
                if (a[i].IsBlocked)
                {
                    if (a[i].IsMoving) Interface.Stop(a[i].ID);
                    if (a[i].IsRotating) Interface.StopRotating(a[i].ID);
                }
                //Console.WriteLine(a[i].ID + ":" + b[jj].ID);
                if (myresources.Count > 0)
                {
                    if (b.Count > 0)
                    {
                        Interface.StartRotating(a[i].ID, b[jj].Rotation);
                        Interface.Attack(a[i].ID, b[jj].ID);
                    }
                    else Interface.StartMoving(a[i].ID);
                }
                else
                {
                    Interface.StartRotatingTo(a[i].ID, xx[kk], yy[kk]);
                    Interface.MoveTo(a[i].ID, xx[kk] + random.Next(382) - 196, yy[kk] + random.Next(382) - 196);
                }
            }

        }

        public static void Main(String[] args)
        {
            String[] temp = new String[2];
            temp[0] = "12";
            temp[1] = "11.55.99";
            SDK.StartGame(temp);
        }
    }
}